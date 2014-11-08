/*
 * bst.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Edward Takahashi
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <stdio.h>
#include <iostream>
using namespace std;

typedef int T;
const int INITSIZE = 1024;

class PQueue {
public:
	PQueue(); //empty constructor
	PQueue(int size); //construct with size initial allocation
	PQueue(T *array, int n);//build PQueue from unsorted array size n
	~PQueue(); //destructor
	void Clear(); //remove and return max element
	void Insert(const T &el); //insert element el into PQueue
	bool Dequeue(T &el); //remove and return max element
	bool FindMax(T &el); //return max element, leaving in place
	bool Empty() const; //is heap empty?
	int Count() const; //number of elements in PQueue
	bool Element(int i, T &el) const; //return element at index i
	int Parent(int i) const; // compute parent index of element i
	int Left(int i) const; // compute left child index of element i
	int Right(int i) const; // compute right child index of element i
	void Breadth() const; // breadth first traversal, printing elements
	T * Sort(int newsize); // Sort and return sorted array. leave empty PQueue.
	
private:
	T * A;
	int sizeA;
	int sizeHeap;
	void HeapifyUp(int i); // help for insert
	void HeapifyDown(int i); // help for dequeue 
	void BuildHeap(); // help for build PQueue from unsorted array
	void Resize(int newsize); // used for insert to make sizeA larger
	
};



#endif /* PQUEUE_H_ */
