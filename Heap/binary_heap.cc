/*
 * Implementation of Max Heap Using Array in C++
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "binary_heap.h"



Heap::Heap(int capacity) : capacity(capacity), count(0){};


int Heap::getParent(int i){
	//Given the index of child returns index of parent
	if(i>count or i==0)
		return -1;
	else
		return  (i-1)/2;
};

int Heap::getLeft(int i){
	//given index returns the index of left child
	if(i>=count)
		return -1;
	else
		return i*2+1;
};

int Heap::getRight(int i){
	//given index returns the index of right child
	if(i>=count)
		return -1;
	else
		return i*2+2;
};

void Heap::insert(int val){
	//Inserts element
	//See left, see right, whichever greater pull it up and run the same insert function on that postion 
	array[count] = val;
	insertRecursive(val, count);
	count ++;
};

void Heap::insertRecursive(int val, int i){
	if(getParent(i)<0 or get(getParent(i))>=val)
		return;
	else{
		//swap 
		int temp = get(getParent(i));
		array[getParent(i)] = val; 
		array[i] = temp;
		insertRecursive(val, getParent(i));
	}
};

int Heap::get(int i){
	//Get element at index i in array;
	if(i>=count) 
		return -1;
	else 
		return array[i];
}

void Heap::set(int i, int val){
	//puts in index i of array val ;
	if(i<count)
		array[i]=val;
	else
		cout << "Index out of Range" << endl;
};

void Heap::printHeap(){
	cout << endl;
	for(int i=0; i<count;i++)
		cout << array[i] << " " ;
	cout << endl << endl;
};

int main(){
	cout << "running main program" << endl;
	Heap v = Heap(100);

	v.insert(20);
	v.insert(25);
	v.insert(30);
	v.printHeap();
	cout << v.get(v.getLeft(0));
}
