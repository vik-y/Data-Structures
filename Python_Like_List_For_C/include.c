#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"

node * newNode(int value){
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void insert(root *n, int value){
  //printf("\nCalling\n");
  	node * val = newNode(value);
    if(n->length==0) {
      n->list = val;
      //printf("add 1 %d\n", n->list->value);
      n->address[0] = val;
      n->length+=1;
    }

    else{
      //Pick address on length -1 position and insert into its next node
        node * temp = n->address[n->length-1];
        //printf("Previous Value %d\n", temp->value);
        temp->next = val;

        n->address[n->length] = val;
        n->length+=1;
        //temp->next = val;
    }
}

int find(root list, int n){
    /*
     * Since the list is not organized, the search would be order n
     * returns 1 if the element you were looking for was found
     * returns 0 if it was not found
     */
     int i;
     for(i=0;i<list.length; i++){
        if(list.address[i]->value == n) return 1;
     }
     return 0;
}

int delete(root list, int index){
    /*
     */
}

int printindex(root n, int index){
    if(index>=n.length){
        printf("Invalid Index");
        return -1;
    }
    else{
        node * temp = n.address[index];
        return temp->value;
    }
}


