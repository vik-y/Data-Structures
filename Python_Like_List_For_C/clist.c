/*
 * Reference - github.com/vik-y/Data-Structures/linked_list
 * Currently supports only integer insertions, non-integer insertions not supported
 */

#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

int main(){
    root newlist;
    //root is a structure which is the root of a linked list, all the lists will be of the type root
    //You can generate multiple lists just like you do in pyton, just use  "root <listname>"
    newlist.length = 0;
    //You must initialize the initial length to be zero whcih means that list doesn't have anything


    insert(&newlist, 10);
    //Insert function takes two arguments
    //Arg1 - address of the list to which you want to add this value
    //Arg2 - the value which you want to insert into the list
    //its just like listname.append(value) in python

    insert(&newlist, 100);
    insert(&newlist, 1000);
    insert(&newlist, 1500);


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
