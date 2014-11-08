//Edward Takahashi
//2-18-11

#include "PQueue.h"

PQueue::PQueue()
{
	A = new T [INITSIZE];
	sizeA = INITSIZE;
	sizeHeap = 0;
}

PQueue::PQueue(int size)
{
	A = new T [size];
	sizeA = size;
	sizeHeap = 0;
}

PQueue::PQueue(T *array, int n)
{
	A = new T [2*n];
	sizeA = 2*n;
	sizeHeap = n;
	for (int i = 0; i < n; i++)
		A[i] = array[i];
	BuildHeap();
	
}

PQueue::~PQueue()
{
    delete []A;
}

void PQueue::Clear()
{
	delete []A;
	A = new T [sizeA];
	sizeHeap = 0;
}

void PQueue::Insert(const T &el)
{
	if (sizeHeap >= sizeA)
		Resize( 2*sizeA );
	A[sizeHeap++] = el;
	HeapifyUp(sizeHeap-1);
}

bool PQueue::Dequeue(T &el)
{
	if (Empty())
		return false;
	el = A[0];
	A[0] = A[--sizeHeap];
	HeapifyDown(0);
	return true;
}

bool PQueue::FindMax(T &el)
{
	if (Empty())
		return false;
	el = A[1];
	return true;
}

bool PQueue::Empty() const
{
	return sizeHeap == 0;
}

int PQueue::Count() const
{
	return sizeHeap;
}

bool PQueue::Element(int i, T &el) const
{
	//cout<< "sizeHeap: " << sizeHeap << endl;
	//cout << "index: " << i << endl;
	if ( (0 <= i) && (i< sizeHeap) )
	{
		//cout<< "A[i]: "<< A[i] << endl;
		el = A[i];
		return true;
	}
	el = -1;
	return false;
		
}

int PQueue::Parent(int i) const
{
	if (i == 0)
		return -1;
	return (i-1)/2;
}

int PQueue::Left(int i) const
{
	if ( (2*i + 1) < sizeHeap)
		return 2*i + 1;
	return -1;
}

int PQueue::Right(int i) const
{
	if ( (2*i +2) < sizeHeap)
		return 2*i + 2;
	return -1;
}

void PQueue::Breadth() const
{
	for (int i =0; i < sizeHeap; i++)
		cout<< A[i] << " ";
	cout<< endl;
	
}

T * PQueue::Sort(int newsize)
{
	T * S = new T [sizeHeap];
	T key;
	for (int i = sizeHeap-1; i > 0; i--)
	{
		Dequeue(key);
		A[i] = key;
	}
	sizeHeap = newsize;
	for (int j = 0; j < sizeHeap; j++)
		S[j] = A[j];
	A = new T [newsize];
	return S;
}
void PQueue::HeapifyUp(int i)
{
	int temp;
	int p = Parent(i);
	while ( (i > 0) && (A[p] < A[i]))
	{
		temp = A[p];
		A[p] = A[i];
		A[i] = temp;
		i = p;
		p = Parent(i);
	}
}

void PQueue::HeapifyDown(int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest;
	T temp;
	
	if ( (l != -1) && (A[l] > A[i]))
		largest = l;
	else
		largest = i;
	
	if ( (r != -1) && (A[r] > A[largest]))
		largest = r;
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		HeapifyDown(largest);
	}
}

void PQueue::BuildHeap()
{
	for (int i = (sizeHeap-1)/2; i >= 0; i--)
		HeapifyDown(i);
}

void PQueue::Resize(int newsize)
{
	int *temp;
  int i;

  sizeA = newsize;
  temp = new int[sizeA];
  for (i=0; i<sizeHeap; i++)
  	temp[i] = A[i];
  delete [] A;
  A = temp;
}
