#Python Like List for C

List in python is very powerful and makes life easy. It's very easy to insert data into the list and also retrieve from it. Also there is no pre-hand memory allocation and also it's possible to delete any value from the list in O(1) time. One of the biggest benefits being that we can store whatever kind of data we want in the python list, the broad idea of this project is to make something like that for C where's there's no memory overhead. Also will try to use the linked list like an array.

##How am I planning to implement it?
I will use a linked list for this. My aim will be to convert linked list insertion from O(n) to O(1) using some memory trade-offs. Also the challenge will be to access it just like array. 

##Memory Constraints 
Every new list which you make, takes up some memory but that is much less memory than what an array of same size will take, and from there on, memory will be allocated dynamically.
32 Bit Integer and 10^6 size of array takes up 32*(10^6) bits of memory, on the other hand, same size of this data structure takes up almost 32*(10^6) + 2*(10^6), so when you have a big array, then this is going to more memory but for an array where you are using smaller number of elements but are not sure about the size of array which you might get to use, this can be a good trad-off

###Reference: 
www.github.com/vik-y/Data-Structures/linked_list
http://stackoverflow.com/questions/20763616/how-many-bytes-do-pointers-take-up

 #Usage:
 --Will Update Soon----
