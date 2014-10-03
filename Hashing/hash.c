/*
 *  hash.c
 *
 *  Created on: 01-Oct-2014s
 */
/*
 * Hashing - By Vikas Yadav
 * github.com/vik-y
 * Hashing using array and linked list
 * You can't create an array greater than 10^6 but you can tweak structures to store much more than 10^9
 * easily.
 * In this code I'll create a structure which you can use exactly like array
 * And then for hashing purpose will make a linked list in each of the indexes
 * Update ->> Delete to be implemented along with freeing the memory space
 */

//Make sure to free the memory

#include <stdio.h>
#include <stdlib.h>

struct arr{
	int value; //To store the value which you want to map into the hash
	struct arr *next; //To support chaining in case of collision
};

typedef struct arr arr;

arr * newNode(){
	//A Helper function to allocate memory dynamically
	arr *newnode;
	newnode = (arr *)malloc(sizeof(arr));
	return newnode;
}


void insert(int val, arr **ip,int index){

	//As we assigned memory to the ip so from (ip+0) to (ip+100) there will be no Null memory so
	//we have to check if the ip->next value is null or not

	if((*ip+index)->next==NULL) {
		printf("\nNull %d\n", val);
		(*ip+index)->value = val;
		(*ip+index)->next = newNode();
		printf("%d test \n", (*ip+index)->value);
	}

	else {
		printf("Else\n");
		arr *temp;
		temp = (*ip+index)->next;
		while(temp->next!=NULL){
			printf("going next\n");
			printf("%d previous value \n", temp->value);
			temp = temp->next;
		}
		temp->value = val;
		temp->next = newNode();
	}
}

int main(int argc, char **argv) {
	arr *ip;
	int length;
	printf("Enter the length of your hash\n");
	scanf("%d", &length);

	ip = (arr *)malloc(length*sizeof(arr)); //Allocating it memory

	int i;

	/*
	 * I am testing values from 0 to 499
	 * Whenever there is a collision, chaining is used to go to the next empty node
	 */


	for(i=0;i<500;i++){
		printf("%d\n", i);
		int index;
		index =i%length;
		insert(i, &ip, index);
	}

	/*
	 * Insertion and chaining working well
	 */
	printf("\n %d", ip->next->value);

}

