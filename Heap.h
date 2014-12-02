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
	backingArray = new std::pair<Pri, T> [arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	std::pair<Pri, T>* tempArray = backingArray;
	arrSize *= 2;
	backingArray = new std::pair<Pri, T> [arrSize];
	for (int i = 0; i < numItems; i++)
		add(tempArray[i]);
	delete[] tempArray;
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
	int parent = (i - 1) / 2;
	if (i > 0 && (backingArray[parent].first > backingArray[i].first)) {
		backingArray[parent].swap(backingArray[i]);
		bubbleUp(parent);
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long i){
	int left = (2 * index) + 1;
	int right = (2 * index) + 2;
	if (backingArray[index].first > backingArray[left].first || backingArray[index].first > backingArray[right].first){
		if (backingArray[left].first < backingArray[right].first && (left < numItems)) {
			backingArray[index].swap(backingArray[left]);
			trickleDown(left);			
		} else if (right < numItems) {
			backingArray[index].swap(backingArray[right]);
			trickleDown(right);
		} else if (left < numItems) {
			backingArray[index].swap(backingArray[left]);
			trickleDown(left);
		}
	}
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if (numItems == 0)
		throw std::string("ERROR: No items to remove.");
	std::pair<Pri,T> x = backingArray[0];
	backingArray[0] = backingArray[numItems-1];
	backingArray[numItems-1] = *(new std::pair<Pri,T>);
	numItems--;
	trickleDown(0);
	return x;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}
