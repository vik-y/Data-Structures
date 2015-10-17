#include <stdio.h>
#include <stdlib.h>

struct list{
	/*
	 * Each node of a linked list will contain the value and the address of the next node
	 */
	int val;
	int *next;
};

typedef struct list list;

list *newNode(int val){
	//A helper function to allocate memory whenever needed
	//Returns the pointer to which memory is allocated 
	list *temp;
	temp = (list *)malloc(sizeof(list));
	temp->val = val;
	return temp;
}

void insert(list **node, list *value){
	/*
	 * I have used extra extra pointer "**node" just to clear to concent of pointers
	 * Same thing can be done with single pointer also "*node" but you have to make a temporary pointer
	 * This is a recursive insertion method - you can also use a while loop to do the same thing. 
	 */
	if(*node==NULL){
		*node = value;
		(*node)->next = NULL;
	}
	else{
		insert(&(*node)->next, value);
	}
}

void printlist(list *node){
	/*A helper function to print all the nodes in the given linked list*/
	if(node!=NULL) {
		printf("%d ", node->val);
		printlist(node->next);
	}
}

int search(list *node, int val){
	//A helper function to search for a value in the given linked_list
	if(node!=NULL){
		if(node->val==val) return 1;
		else search(node->next, val);
	}
}

void delete(list **node, int val){
	if(*node!=NULL){
		if((*node)->val==val){
			*node = (*node)->next;
			//Deallocate memory here.
			return;
		}
		else delete(&(*node)->next, val);
	}
}


int main(int argc, char **argv) {
	list *head = NULL; 
	int count = 5;
	while(count >0){
		//Testing
		//Insertion and printlist working completely fine
		//Search Working Completely Fine
		int temp;
		scanf("%d", &temp);
		insert(&head, newNode(temp));
		printlist(head);
		printf("\n");
		count --;
	}

	count = 5;
	while(count>0){
		int temp;
		scanf("%d", &temp);
		printlist(head);
		printf("\n");
		delete(&head, temp);
		printlist(head);
		printf("\n");
		count --;
	}
}
