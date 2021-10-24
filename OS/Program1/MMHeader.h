#ifndef MMHEADER_H
#define MMHEADER_H

#include <sys/mman.h>   //for mmap()
#include <stdio.h>
#include <stdlib.h>

typedef struct __mmalloc_t
{
	int size;
    int magic;
    double padding; //Won't have to deal with this
} mmalloc_t;

typedef struct __mmfree_t
{
	int size;   //size of free space & doesn't include header
    struct __mmfree_t* next;
} mmfree_t;

mmfree_t* head;

void* mem_manager_malloc(int size);
void mem_manager_free(void* ptr);
//traverse the free space list starting from the head, printing out info (for debugging)
void traverse_free_list(); 
void init_mem(int free_space_size);
//called by malloc
//find a free space chunk large enough for the requested allocation
//obtain some memory from that chunk
mmfree_t* locate_split(mmfree_t* current, int requestedSize);
//called by free
//locate the freed memory insert position so free space nodes are sorted by address
mmfree_t* find_sorted_location(mmfree_t* current, mmfree_t* insertPos);
void coalesce(mmfree_t* current);


void* mem_manager_malloc(int size){
    //Merge
    if(head->next != NULL){
        coalesce(head);
    }
    //16 byte headers
    int requestedSize = size + 16;
    //Holds the memory address
    mmalloc_t* memAdd = (void*)locate_split(head, requestedSize);    
    memAdd->size = size;
    memAdd->magic = 1234567; 
    long memAddress = (long)memAdd;
    //updated address
    void* updatedAdd = (void*)memAddress + 16;
    return updatedAdd;
}

void mem_manager_free(void* ptr){

    if(head->next != NULL){
        coalesce(head);
    }

    long pointer = (long)ptr;
	void* myptr = (void*)pointer - 16;
	mmalloc_t* hptr = (mmalloc_t*) myptr;
	int size = hptr->size;
	mmfree_t* newNode = myptr;
	newNode->size = size;
	newNode->next = NULL;
	mmfree_t* location = find_sorted_location(head, newNode);	
}

void traverse_free_list(){
    if(head->next != NULL){
        coalesce(head);
    }
    mmfree_t* temp = (void*)head;
    while(temp != NULL){
        temp = (void*)temp->next;
    }
} 

void init_mem(int free_space_size){
    int allocatedHeaderSize = (int)sizeof(mmalloc_t);
    int freeSize = (int) sizeof(mmfree_t);

    // mmap() returns a pointer to a chunk of free space and builds heap
    head = mmap((void*)NULL, free_space_size, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
    head->size = free_space_size - sizeof(mmfree_t);
    head->next = NULL;

    printf("curr: %p\r\n", head);
	printf("size: %d\r\n", head->size);
    printf("\n");    
}

mmfree_t* locate_split(mmfree_t* current, int requestedSize){
    if(current->size > requestedSize){
        long curr = (long)current;
        head = (void*)curr + requestedSize;
        head->size = current->size - requestedSize;
        head->next = current->next;
        return current;
    }
    else
    {
        mmfree_t* previous;
        while(current != NULL){
            if(current->size > requestedSize){
                int newSize = current->size - requestedSize;
                mmfree_t* nextNode = (mmfree_t*)current->next;
                long temp = (long)current;
                mmfree_t* newNode = (void*)temp + requestedSize;
                newNode->size = newSize;
                newNode->next = (void*)newNode;
                return current;
                break;
            }
            previous = current;
            current = (mmfree_t*)current->next;
        }
    }
}

mmfree_t* find_sorted_location(mmfree_t* current, mmfree_t* insertPos){
    long newNode = (long)insertPos;
	long currNode = (long)current;
	if(currNode > newNode)
	{
		insertPos->next = (void*)current;
		head = (mmfree_t*)insertPos;
		return current;
	} 
	else
	{
		mmfree_t* previous;
		while(current != NULL)
		{	
			if(currNode > newNode)
			{
				insertPos->next = (void*)current;
				previous->next = (void*)insertPos;
				return current;
				break;
			}
			previous = current;
			current = (mmfree_t*)current->next;
			currNode = (long)current;
		}
	}
}

void coalesce(mmfree_t* current){
    if(current->next != NULL){
        mmfree_t* previous = current;
        while(current != NULL){
            int updatedSize = previous->size + current->size;
            int prevSize = (int)previous->size;
            long temp1 = (long)previous + prevSize + 16;
            long temp2 = (long)current;

            if(temp1 == temp2 && previous != current){
                previous->size = updatedSize + 16;
                previous->next = (void*)current->next;
            }

            previous = current;
            current = (mmfree_t*)current->next;

        }
    }
}

#endif
     