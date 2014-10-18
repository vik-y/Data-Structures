#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * next;
};


struct root{
    //the next null node is given by the length;
    //eg if lengt = 0 is the 0th node is null so the list is empty 
    int * r[1000];
    int length;
    struct node *list;
};

typedef struct root root;
typedef struct node node;

node * newNode(int value){
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->value = value;
    return temp;
}

void insert(root n, node * val){
    no
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

int main(){
    root newlist;
    newlist->length = 0;
    insert(newlist, newNode(10));
}
