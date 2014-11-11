#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
* This is a priority queue, which means that as items are removed in order
* of decreasing priority.
*
* 
*/
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
	Heap();
	~Heap();

	//Add a new item
	virtual void add(std::pair<Pri,T> toAdd);

	//Remove the item with lowest priority, and return it
	//If the queue is empty, throw a string exception
	virtual std::pair<Pri,T> remove();

	//Return the number of items currently in the queue
	virtual unsigned long getNumItems();

private:
	int arrSize;
	int numItems;
	std::pair<Pri, T>* backingArray;

	//Grow the backingArray by making a new array of twice the size,
	// and copying over the data
	void grow();

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it up the "tree" of the heap until you find the right
	// place
	void bubbleUp(unsigned long index);

	//Check the item at index, and make sure it is in the right place.
	// If not, swap it down the "tree" of the heap until you find the right
	// place
	void trickleDown(unsigned long index);  
};


//Author: Sam Bowdler
//Date: 2014/11/6

#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	arrSize=START_SIZE;
	numItems=0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete backingArray;
}

int parent(int i) {
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int right(int i) {
	return 2 * i + 2;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	std::pair<Pri, T>* tmp = new std::pair<Pri, T>[arrSize * 2];

	for(int i = 0; i < arrSize; i++)
		tmp[i] = backingArray[i];

	arrSize *= 2;
	delete[] backingArray;
	backingArray = tmp;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	if (numItems + 1 > arrSize)
		grow();
	backingArray[numItems++] = toAdd;
	bubbleUp(numItems - 1);
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long i){
	int p = parent(i);
	while (i > 0 && backingArray[i] < backingArray[p]) {
		backingArray.swap(i,p);
		i = p;
		p = parent(i);
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long i){
	do {
		int j = -1;
		int r = right(i);
		if (r < numItems && backingArray[r] < backingArray[i]) {
			int l = left(i);
			if (backingArray[l] < backingArray[r])
				j = l;
			else
				j = r;
		} else {
			int l = left(i);
			if (l < numItems && backingArray[l] < backingArray[i])
				j = l;
		}
		if (j >= 0) {
			int tmp = backingArray[i];
			backingArray[i] = backingArray[j];
			backingArray[j] = tmp;
		}
		i = j;
	} while (i >= 0);
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	std::pair<Pri,T> x = backingArray[0];
	backingArray[0] = backingArray[--numItems];
	trickleDown(0);
	return x;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}