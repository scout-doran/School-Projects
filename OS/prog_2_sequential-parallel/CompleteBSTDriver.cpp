#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#include "BinarySearchTree.h"
using CSC1310::BinarySearchTree;
#include "BinaryTreeIterator.h"
using CSC1310::BinaryTreeIterator;
#include "ListArray.h"
using CSC1310::ListArray;
#include "ListArrayIterator.h"
using CSC1310::ListArrayIterator;

#include "Permutation.h"
using CSC1310::Permutation;
#include "Random.h"
using CSC1310::Random;
#include "CD.h"

#include <pthread.h>
#include <mutex>

#include <iostream>
using namespace std;

//Make sure you test more producers than consumers and vice versa
//You have a lot less probs when they are the same #
//Ex. buffer = 1, p = 1, c=1
int BUFFER_SIZE = 100;
int NUM_PRODUCERS = 50;
int NUM_CONSUMERS = 10;

int NUM_TREES = 10000; // Creating 10,000 trees
int ERROR_RATE = 10;


//NOTE: The buffer is a triple ptr
//		The buffer is an array that contains cds_array
//		One * comes from the buffer itself since it is an object
//		cds_array has ** which makes the buffer object a triple ptr
CD*** buffer;
int buffer_count = 0;
int producer_index = 0;
int consumer_index = 0;

int num_trees_p = 0;
int num_trees_c = 0;

//For parallel
pthread_cond_t empty, full = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

CD** producer_seq(ListArray<CD>* cds, Random* rand);
void consumer_seq(CD** cds_array, int num_items, int expected_height);
void deleteCDs(ListArray<CD>* list);
void put(CD** cds_array);
CD** get();
//HINT!!! When you write parallel methods the return type is void* and the argument is also void*
void* producer_parallel(void *arg);
void* consumer_parallel(void *arg);

int main()
{
	buffer = new CD**[BUFFER_SIZE];
	time_t start, end;
	//the unsorted ListArray of cds
    Random* rand = Random::getRandom();
    ListArray<CD>* cds = CD::readCDs("cds.txt");
    int num_items = cds->size();
    int expected_height = ceil(log2(num_items + 1));

    cout << num_items << endl;
    cout << "based on the number of items, the min height should be: " << endl;
    cout << expected_height << endl;
    cout << endl;

    //NOTE: We will be unpacking these parameters when we write the parallel methods
    //long producer_args[2]; // Original <- Modify
    long* producer_args = new long[2];
    producer_args[0] = (long) cds;
    producer_args[1] = (long) rand;

    //int consumer_args[2];
    int* consumer_args = new int[2];
    consumer_args[0] = num_items;
    consumer_args[1] = expected_height;

            /*
            //sequential solution: process one tree at a time
           	start = time(NULL);

        	for (int i = 1; i <= NUM_TREES; i++)
        	{
        	    CD** cd_array = producer_seq(cds, rand);
        		consumer_seq(cd_array, num_items, expected_height);
        	}

            end = time(NULL);
            printf("sequential: %ds\n", (int)(end - start));
            */

	//parallel
    pthread_t producer_array[NUM_PRODUCERS];
    pthread_t consumer_array[NUM_CONSUMERS];
    //Contains 2 *arrays
    long** p_args = &producer_args;
    int** c_args = &consumer_args;

    start = time(NULL);

    //create
    for(int i = 0; i<NUM_PRODUCERS; i++){
     	pthread_create(&producer_array[i], NULL, producer_parallel, (void *)p_args);
    }
    for(int i = 0; i<NUM_CONSUMERS; i++){
      	pthread_create(&consumer_array[i], NULL, consumer_parallel, (void *)c_args);
    }

    //join
    for(int i = 0; i<NUM_PRODUCERS; i++){
       	pthread_join(producer_array[i], NULL);
    }
    for(int i = 0; i<NUM_CONSUMERS; i++){
       	pthread_join(consumer_array[i], NULL);
    }

    end = time(NULL);
    printf("parallel: %ds\n", (int)(end - start));

	deleteCDs(cds);
    delete cds;
    delete[] buffer;
	delete[] producer_args;
	delete[] consumer_args;

   return 0;
}

//Put and get
void put(CD** cds_array)
{
	buffer[producer_index] = cds_array;
	producer_index = (producer_index + 1) % BUFFER_SIZE;
	buffer_count++;  //buffer fills up
}
CD** get()
{
	CD** cds_array = buffer[consumer_index];
	consumer_index = (consumer_index + 1) % BUFFER_SIZE;
	buffer_count--;  //buffer empties out
	return cds_array;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

//NOTE: Be careful where you call this method... remember critical section of code wants to be as small as possible
//		Otherwise the parallel will be running just as slow as the sequential
//		Do you really need this method in your critical section?
CD** producer_seq(ListArray<CD>* cds, Random* rand)
{
//1.  get an array with the cds in a random order
	    int num_items = cds->size();
		Permutation* p = new Permutation(num_items, num_items, rand);
		p->basicInit();

		CD** permute_cds = new CD*[num_items];
		int count = 0;
		while(p->hasNext())
		{
			int i = p->next();
			permute_cds[count] = cds->get(i);
			count++;
		}
		delete p;

//2.  insert the cds in array order (different each time) into BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < num_items; i++)
		{
			CD* cd = permute_cds[i];
			bst->insert(cd);
		}
		delete[] permute_cds;

//3.  create a complete binary search tree
//NOTE: This is the most time consuming step!!!
		BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
		CD** cds_array = new CD*[num_items];
		BinaryTreeIterator<CD>* complete_iter = complete_bst->iterator();

//4.  place the cds into an array using a level order traversal
		//intentionally inserting an error in some cases using a post order traversal
		int traversal_error = rand->getRandomInt(1, NUM_TREES);
		if (traversal_error >= ERROR_RATE)
		{
			complete_iter->setLevelorder();
		}
		else
		{
			//wrong traversal, consumer should detect a height error
			//still will be sorted, however
			complete_iter->setPostorder();
		}
		count = 0;
		while(complete_iter->hasNext())
		{
			cds_array[count] = complete_iter->next();
			count++;
		}
		delete bst;
		delete complete_iter;
		delete complete_bst;

//5.  return the array that is supposed to represent a complete binary tree
		return cds_array;
}

//NOTE: cds_array is the thing that will be placed on the buffer
//		Once the producer produces the array, it gets dumped
//		And the consumer when its ready to consume it pulls it from the buffer
void consumer_seq(CD** cds_array, int num_items, int expected_height)
{
//1.  put the items in the provided array into a BST
//note that if the array represents a complete binary tree,
//this process will create a complete binary tree that is also a BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < num_items; i++)
		{
			CD* cd = cds_array[i];
			bst->insert(cd);
		}

//2.  verify that the items are in sorted order using an inorder traversal
		BinaryTreeIterator<CD>* bst_iter = bst->iterator();
		bst_iter->setInorder();  //this was omitted
		CD* first = bst_iter->next();
		bool sorted = true;
		while(bst_iter->hasNext())
		{
			CD* second = bst_iter->next();
			if (CD::compare_items(first, second) >= 0)
			{
				sorted = false;
				break;
			}
			first = second;
		}
		delete bst_iter;

//3.  check that the BST is minimum height and balanced
//the randomly determined errors will fail the height test
		int h = bst->getHeight();
		bool bal = bst->isBalanced();

		if (!sorted || h != expected_height || !bal)
		{
			cout << "invalid complete binary tree" << endl;
		}
		else
		{
			//cout << "valid complete binary tree" << endl;
		}

		delete bst;
		delete[] cds_array;
}


/********** Parallel Functions Below **********/

void* producer_parallel(void *args){
    long** temp =(long**)args;
    long* arg_array = *temp;
    ListArray<CD>* cds = (ListArray<CD>*) arg_array[0];
    Random* rand = (Random*) arg_array[1];

	while(buffer_count <= BUFFER_SIZE || num_trees_p < NUM_TREES){

		//1.  get an array with the cds in a random order
    	int num_items = cds->size();

		Permutation* p = new Permutation(num_items, num_items, rand);
		p->basicInit();

		CD** permute_cds = new CD*[num_items];
		int count = 0;
		while(p->hasNext())
		{
			int i = p->next();
			permute_cds[count] = cds->get(i);
			count++;
		}
		delete p;

		//2.  insert the cds in array order (different each time) into BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < num_items; i++)
		{
			CD* cd = permute_cds[i];
			bst->insert(cd);
		}
		delete[] permute_cds;

		//3.  create a complete binary search tree
		//NOTE: This is the most time consuming step!!!
		BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
		CD** cds_array = new CD*[num_items];
		BinaryTreeIterator<CD>* complete_iter = complete_bst->iterator();

		//4.  place the cds into an array using a level order traversal
		//intentionally inserting an error in some cases using a post order traversal
		int traversal_error = rand->getRandomInt(1, NUM_TREES);
		if (traversal_error >= ERROR_RATE)
		{
			complete_iter->setLevelorder();
		}
		else
		{
			//wrong traversal, consumer should detect a height error
			//still will be sorted, however
			complete_iter->setPostorder();
		}
		count = 0;
		while(complete_iter->hasNext())
		{
			cds_array[count] = complete_iter->next();
			count++;
		}

		delete bst;
		delete complete_iter;
		delete complete_bst;

		//5.  return the array that is supposed to represent a complete binary tree


		pthread_mutex_lock(&m);     //LOCK
		while(buffer_count >= BUFFER_SIZE && num_trees_p < NUM_TREES){
		    pthread_cond_wait(&empty, &m);
		}
		//Terminate Thread
		while(num_trees_p >= NUM_TREES){
		    pthread_cond_signal(&full);
		    pthread_cond_signal(&empty);
            pthread_mutex_unlock(&m);   //UNLOCK
            //When producer is done producing can put NULL on the buffer to indicate that they are done
            return NULL;
		}

		//Added one to the buffer therefore increment producer trees
        num_trees_p++;

		//put array on buffer
		put(cds_array);
		//Signal that the buffer is full
		pthread_cond_signal(&full);
		pthread_mutex_unlock(&m);   //UNLOCK
	}
}

void* consumer_parallel(void *args){

    int** temp =(int**)args;
    int* arg_array = *temp;
   	int num_items = arg_array[0];
   	int expected_height = arg_array[1];

	while(buffer_count >= 0 || num_trees_c < NUM_TREES){
		pthread_mutex_lock(&m);     //LOCK
		while(buffer_count <= 0 && num_trees_c < NUM_TREES){
			pthread_cond_wait(&full, &m);
		}
		//Terminate thread
		while(num_trees_c >= NUM_TREES){
		    pthread_cond_signal(&empty);
            pthread_cond_signal(&full);
            pthread_mutex_unlock(&m);   //UNLOCK
            return NULL;
		}

        //Remove from buffer
		CD** temp_array = get();
		//removed one from the buffer therefore increment consumer trees
        num_trees_c++;
        //Signal that the buffer is empty
		pthread_cond_signal(&empty);	//Has to match with producer cond_wait()
		pthread_mutex_unlock(&m);   //UNLOCK


	//1.  put the items in the provided array into a BST
	//note that if the array represents a complete binary tree,
	//this process will create a complete binary tree that is also a BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < num_items; i++)
		{
			CD* cd = temp_array[i];
			bst->insert(cd);
		}

	//2.  verify that the items are in sorted order using an inorder traversal
		BinaryTreeIterator<CD>* bst_iter = bst->iterator();
		bst_iter->setInorder();  //this was omitted
		CD* first = bst_iter->next();
		bool sorted = true;
		while(bst_iter->hasNext())
		{
			CD* second = bst_iter->next();
			if (CD::compare_items(first, second) >= 0)
			{
				sorted = false;
				break;
			}
			first = second;
		}
		delete bst_iter;

	//3.  check that the BST is minimum height and balanced
	//the randomly determined errors will fail the height test
		int h = bst->getHeight();
		bool bal = bst->isBalanced();

		if (!sorted || h != expected_height || !bal)
		{
			cout << "invalid complete binary tree" << endl;
		}
		else
		{
			//cout << "valid complete binary tree" << endl;
		}

		delete bst;
		delete[] temp_array;
	}
}
