#include <stdio.h>
#include <stdlib.h>

struct list{
	int val;
	int *next;
};

typedef struct list list;

list *newNode(int val){
	list *temp;
	temp = (list *)malloc(sizeof(list));
	temp->val = val;
	return temp;
}

void insert(list **node, list *value){
	if(*node==NULL){
		*node = value;
		(*node)->next = NULL;
	}
	else{
		insert(&(*node)->next, value);
	}
}

void printlist(list *node){
	if(node!=NULL) {
		printf("%d ", node->val);
		printlist(node->next);
	}
}

int search(list *node, int val){
	if(node!=NULL){
		if(node->val==val) return 1;
		else search(node->next, val);
	}
}

void delete(list **node, int val){
	if(*node!=NULL){
		if((*node)->val==val){
			*node = (*node)->next;
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
