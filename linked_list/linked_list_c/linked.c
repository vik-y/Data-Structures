#include <stdio.h>
#include <stdlib.h>

struct lnode{
	/*
	 * Each node of a linked list will contain the value and the address of the next node
	 */
	int val;
	struct lnode *next;
};

typedef struct lnode lnode;

lnode *newNode(int val){
	//A helper function to allocate memory whenever needed
	//Returns the pointer to which memory is allocated 
	lnode *temp;
	temp = (lnode *)malloc(sizeof(lnode));
	temp->val = val;
	return temp;
}

void insert_recursive(lnode **node, int value){
	// Working
	if(*node==NULL){
		*node = newNode(value);
		(*node)->next = NULL;
	}
	else{
		insert_recursive(&(*node)->next, value);
	}
}

lnode * insert_linear(lnode *node, int value){
	lnode *t = node;
	if(node==NULL){
		node = newNode(value);
		printf("Inserted %d\n", node->val);
		return node;
	}
	while(node->next!=NULL){
		node=node->next;
	}
	node->next = newNode(value);
	return t;
}

void printlist(lnode *node){
	/*A helper function to print all the nodes in the given linked list*/
	if(node!=NULL) {
		printf("%d ", node->val);
		printlist(node->next);
	}
	else
		printf("NULL");
}

int search(lnode *node, int val){
	//A helper function to search for a value in the given linked_list
	if(node!=NULL){
		if(node->val==val) return 1;
		else search(node->next, val);
	}
}

void delete(lnode **node, int val){
	// Can be done linearly also
	if(*node!=NULL){
		if((*node)->val==val){
			lnode *temp;
			temp = *node;
			*node = (*node)->next;
			free(temp);
			// Memory deallocation done
			return;
		}
		else delete(&(*node)->next, val);
	}
}

lnode * reverse_recursive(lnode *current, lnode *prev){
	lnode * rnode = current; // Creating a temporary node 
	if(current->next!=NULL){
		rnode = reverse_recursive(current->next, current);
		// Take the next node of current node and set current node as 
		// previous node for next node of current node. 
		// E.g If we have 5->1 then current node is 5 and next node is 1
		// calling reverse_recursive on it will do this: 5<-1 
	}
	current->next = prev; 
	return rnode;
}

int main(int argc, char **argv) {
	lnode *head = NULL;
	int count = 5;
	while(count >0){
		//Testing
		//Insertion and printlist working completely fine
		//Search Working Completely Fine
		int temp;
		scanf("%d", &temp);
		head = insert_linear(head, temp);
		printlist(head);
		printf("\n");
		count --;
	}

	/*count = 5;
	while(count>0){
		int temp;
		scanf("%d", &temp);
		printlist(head);
		printf("\n");
		delete(&head, temp);
		printlist(head);
		printf("\n");
		count --;
	}*/
	
	head = reverse_recursive(head, NULL);
	printf("Printing Reversed List \n");
	printlist(head);
}
