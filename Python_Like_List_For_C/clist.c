/*
 * Reference - github.com/vik-y/Data-Structures/linked_list
 * Currently supports only integer insertions, non-integer insertions not supported
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * next;
};


struct root{
    //the next null node is given by the length;
    //eg if lengt = 0 is the 0th node is null so the list is empty
    struct node * address[1000];
    int length;
    struct node *list;
};

typedef struct root root;
typedef struct node node;

node * newNode(int value){
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void insert(root *n, node * val){
  //printf("\nCalling\n");
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




int main(){
    root newlist;
    //root is a structure which is the root of a linked list, all the lists will be of the type root
    //You can generate multiple lists just like you do in pyton, just use  "root <listname>"
    newlist.length = 0;
    //You must initialize the initial length to be zero whcih means that list doesn't have anything


    insert(&newlist, newNode(10));
    //Insert function takes two arguments
    //Arg1 - address of the list to which you want to add this value
    //Arg2 - the value which you want to insert into the list
    //its just like listname.append(value) in python

    insert(&newlist, newNode(100));
    insert(&newlist, newNode(1000));
    insert(&newlist, newNode(1500));


    while(1){
        int s;
        scanf("%d", &s);
        printf("%d\n", find(newlist, s));
    }
    //printf("%d\n", printindex(newlist, 0));
    //printf("%d\n", printindex(newlist, 1));
    //printf("%d\n", printindex(newlist, 2));
    //printf("%d\n", newlist.list->value);
    //printindex(newlist,0);
}
