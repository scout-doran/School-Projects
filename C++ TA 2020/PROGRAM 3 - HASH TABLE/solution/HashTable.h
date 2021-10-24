/*
	Title:  HashTable.h
	Author:	April Crockett
	Purpose:  	Hash Table Implementation
				Values					-	integers
				Hash Function			-	modulus operator
				Collision resolution	-	linear probing
				
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

template <typename T>
class HashTable
{
	private:
		int tableSize;
		HashEntry<T>** hashArray;
		int numHashEntries;
		
	public:
		HashTable(int size)
		{
			tableSize = size;
			hashArray = new HashEntry<T>*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
			numHashEntries = 0;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<T> *prevEntry = NULL;
					HashEntry<T> *entry = hashArray[i];
					while(entry != NULL)
					{
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}
		
		int getNumHashEntries()
		{
			return numHashEntries;
		}
		
		T getValue(int key)
		{
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL)
			{
				return NULL;
			}
			else
			{
				HashEntry<T> *entry = hashArray[bucketIndex];
				while(entry != NULL && entry->getKey() != key)
					entry = entry->getNext();
				if(entry == NULL)
					return NULL;
				else
					return entry->getValue();
			}
		}
		
		void putValue(int key, T value)
		{
			int bucketIndex = key % tableSize;
			//cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = new HashEntry<T>(key, value);
			}
			else //collision
			{
				HashEntry<T>* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry<T>(key, value));
			}
			numHashEntries++;
		}
		
		void removeValue(int key)
		{
			HashEntry<T> *entry;
			HashEntry<T> *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL)
			{
				//traverse through list and find matched key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL & entry->getKey() != key)
				{
					prevEntry = entry;
					entry = entry->getNext();
				}
				if(entry->getKey() == key) //found the key in previous while loop
				{
					numHashEntries--;
					if(prevEntry == NULL)
					{
						HashEntry<T> *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}
					else
					{
						HashEntry<T> *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
					}
				}
			}		
		}
		
		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				cout << "BUCKET " << i << " ";
				if(hashArray[i] != NULL)
				{
					HashEntry<T>* entry = hashArray[i];
					while(entry->getNext() != NULL)
					{
						cout << "---->" << *(entry->getValue());
						entry = entry->getNext();
					}
					cout << "---->" << *(entry->getValue());
					cout << "\n";
				}
				else
					cout << "NULL" << "\n";
			}
			cout << "----------\n\n";
		}
	
};


#endif