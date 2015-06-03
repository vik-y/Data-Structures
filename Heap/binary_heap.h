class Heap{
	int count;
	int capacity;
	int array[];
public:
	Heap(int capacity);
	void printHeap();
	void insert(int val);
	void insertRecursive(int val, int i);
	int deleteMax();
	int getParent(int i);
	int getLeft(int i);
	int getRight(int i);
	int get(int i);
	void set(int i, int val);
	int del(int val);
	int delMax();
	void heapify(int index);
	void delRecursive(int index);
	int findElement(int val);
};
