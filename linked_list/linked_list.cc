/*
 * A Simple Linked List in C++
 * Author - Vikas Yadav
 */
#include <iostream>
using namespace std;

 class Node{
 public:
   int val;
   Node *next;
   Node(int v): val(v){
     next = NULL;
   };
   Node();
   ~Node(){
     delete next;
   }
};

class Linked_List{
   int length;
public:
   Linked_List(){
     length = 0;
   };
   ~Linked_List(){
     delete root_node;
   }
   Node * root_node;
   void insert(int val){
     if(length==0) {
       root_node = new Node(val);
       length+=1;
     }
     else{
       Node * temp = root_node;
       while(temp->next!=NULL){
         temp = temp->next;
       }
       temp->next = new Node(val);
       length+=1;
     }
   };

   void printList(){
     Node * temp = root_node;
     while(temp!=NULL){
       cout << temp->val << " " ;
       temp=temp->next;
     }
     //temp->next = new Node(val);
   };
};

 int main(){
   //cout << "run";
   Linked_List vik;
   vik.insert(5);
   vik.insert(10);
   vik.insert(20);
   vik.insert(30);
   vik.insert(40);
   vik.printList();
   cout << endl;

}
