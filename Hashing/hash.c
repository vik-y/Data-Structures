/*
 *  hash.c
 *
 *  Created on: 01-Oct-2014s
 */
/*
 * Hashing - By Vikas Yadav
 * github.com/vik-y
 * Hashing using array and linked list
 * You can't create an array greater than 10^6
 * In this code I'll create a structure which you can use exactly like array
 * And then for hashing purpose will make a linked list in each of the indexes
 */

//Make sure to free the memory in this code as well as all the codes which you have written before this

#include <stdio.h>
#include <stdlib.h>

struct arr{
	int value;
	struct arr *next;
};

struct linkednode{
	int *value;
	struct linkednode *next;
};
typedef struct linkednode linkednode;
typedef struct arr arr;

arr * newNode(int val){
	linkednode *newnode;
	newnode = malloc(sizeof(int));
	newnode->value = val;
	return newnode;
}

//Allocating memory to the pointer so that it can be used as an array



int main(int argc, char **argv) {

	arr *ip = malloc(1000000000*sizeof(int));
	//Testing for NULL Condition
	if(ip[0].value==NULL){
		printf("Null");
	}
	else{
		printf("Working\n");
		printf("Value %d\n");
	}
	//Working well
	int i;
	for(i=0;i<100;i++){
		insert(i, ip);
	}
	printf("Index 0 %d\n", ip[0].value);
	printf("Index 0 next%d\n", ip[0].next->value);
}

