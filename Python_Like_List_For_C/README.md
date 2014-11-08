#Python Like List for C

List in python is very powerful and makes life easy. It's very easy to insert data into the list and also retrieve from it. Also there is no pre-hand memory allocation and also it's possible to delete any value from the list in O(1) time. One of the biggest benefits being that we can store whatever kind of data we want in the python list, the broad idea of this project is to make something like that for C where's there's no memory overhead. Also will try to use the linked list like an array.

##Implementation
I am using a linked list for this. I am converting linked list insertion from O(n) to O(1) using some memory trade-offs. I have also added array type support so that you can access the entire linked list just like an array. 

##Memory Constraints 
Every new list which you make, takes up some memory but that is much less memory than what an array of same size will take, and from there on, memory will be allocated dynamically.
<br>
Run this Code on Your Machine to see how much memory does a pointer take on your system, these value change depending on your system architecutre. 
```
#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};


int main(){
	printf("%ld bytes per integer\n", sizeof(int));
	printf("%ld bytes per integer pointer\n", sizeof(int *));
	printf("%ld bytes per long int\n", sizeof(long int));
	printf("%ld bytes per long int pointer\n", sizeof(long int *));
	printf("%ld bytes per double \n", sizeof(double));
	printf("%ld bytes per double pointer\n", sizeof(double *));
	printf("%ld bytes per char\n", sizeof(char));
	printf("%ld bytes per char pointer\n", sizeof(char *));
	printf("%ld bytes per node \n", sizeof(struct node));
	printf("%ld bytes per node pointer\n", sizeof(struct node *));
	printf("%ld bytes per pointer\n", sizeof(void *));
}
```
Output
```
4 bytes per integer
8 bytes per integer pointer
8 bytes per long int
8 bytes per long int pointer
8 bytes per double 
8 bytes per double pointer
1 bytes per char
8 bytes per char pointer
16 bytes per node 
8 bytes per node pointer
8 bytes per pointer
```
As we can see, each pointer takes up memory of 8bytes irrespective of the element which it is pointing to. So in my linked list data structure if you want it to store at max 1000 elements then you have to allocate it 8*1000 bytes in advance. Whereas using the array in the same scenario costs about 4*1000 bytes which makes it look as a bit ineffective but in real life you'll be making bigger structures in which you'll be storing data much bigger than 8 bytes, in those cases, this will be a very efficient data structure as no matter what you store the memory that a pointer uses is always 8 bytes.  


###Reference: 
www.github.com/vik-y/Data-Structures/linked_list<br>
http://stackoverflow.com/questions/20763616/how-many-bytes-do-pointers-take-up

###Usage:
Include the clist.h file along with other relevant libraries, e.g.
```
#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
```
Compile Using this command
```
gcc clist.c include.c -o clist
```

Modify the main function in the file main.c as per your requirements.<br>

<b>Functions</b>
<ol>
<li>Defining a new list
```
root newlist; //Here root is the structure name and newlist is the name of the newlist which you are forming
```</li>
<li>Inserting into the list
```
insert(&newlist, 100); //Here 100 is the value which you want to insert and &newlist is the address of the newlist which you defined in 1
```
</li>
<li>Delete Will Update </li>
</ol>

