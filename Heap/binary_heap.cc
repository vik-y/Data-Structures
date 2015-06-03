/*
 * Implementation of Max Heap Using Array in C++
 * Debug the segmentation fault.
 * DelMax() Working now
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "binary_heap.h"

void swap(int &a, int &b){
	int temp = a;
	
}

Heap::Heap(int capacity) : capacity(capacity), count(0){
for(int i=0;i<capacity;i++)
	array[i]=-1;
};


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

//Start Coding from here 

int Heap::del(int val){
	//return 1 if found and deleted
	//else return 0
	/*
	 */
	int i = findElement(val);
	if(i==-1)
		return 0;
	else{
		cout << "i " << i << endl;
		delRecursive(i);
		count --;
		return 1;
	}
};

int Heap::delMax(){
	//return 1 if found and deleted
	//else return 0
	/*
	 * Logic to delete Maximum element
	 * Swap the element at 0 index with the last index and then heapify 
	 */
	if (count==0) return 0;
	else {
		swap(array[0], array[count-1]);
		heapify(0);
		count --;
	}
	
};

void Heap::heapify(int index){
	//Logic to heapify the heap
	//check children, swap with the greatest 
	if (index>=count) return;
	int l, r, max; 
	l = getLeft(index);
	r = getRight(index);
	if(l==-1 && r==-1)
		return; 
	if(l>0 && r>0){
			if(array[l] > array[r]) max = l;
			else max = r;
		}
	else if (l >0) max =l;
	else if( r > 0) max = r;
	else {
		 array[index]=-1;
		 return;
	 }	
	
	array[index] = array[max];
	heapify(max);
}

void Heap::delRecursive(int index){
	// reducing the count of number of elements  
	//Do the deletion work here, delete and swap, do in recursion 
	//getLeft child
	//get Right child swap with the largest child and do recursively
	if (index>=count) return;
	int l, r, max; 
	l = getLeft(index);
	r = getRight(index);
	cout << l << "  " << r << " " ;
	if(l==-1 && r==-1)
		return; 
	//if(l>0) max = l;
	//else if(r>0 && 	l>0 && array[r]>array[l]) max = r;
	if(l>0 && r>0){
			if(array[l] > array[r]) max = l;
			else max = r;
		}
	else if (l >0) max =l;
	else if( r > 0) max = r;
	else {
		 array[index]=-1;
		 return;
	 }	
	
	array[index] = array[max];
	delRecursive(max);
};

int Heap::findElement(int val){
	//return 1 if found
	//else return 0
	for(int i=0;i<count;i++){
		if(val==array[i])
			return i;
		}
	return -1;
};



int main(){
	cout << "running main program" << endl;
	Heap v = Heap(100);

	v.insert(20);
	v.printHeap();
	
	v.insert(25);
	v.printHeap();
	
	v.insert(30);
	v.printHeap();
	
	v.insert(80);
	v.printHeap();
	
	v.insert(100);
	v.printHeap();
	
	v.insert(1);
	v.printHeap();
	
	v.insert(2);
	v.printHeap();
	
	v.insert(105);
	v.printHeap();
	
	v.insert(1000);
	v.printHeap();
	
	v.delMax();
	v.printHeap();
	
	v.delMax();
	v.printHeap();
	
	cout << "Came till here " << endl;
	//cout << v.get(v.getLeft(0));
}
