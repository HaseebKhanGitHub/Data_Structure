#include <iostream>
using namespace std;
struct Node { 
   char data; 
   struct Node *next; 
}; 
 Node *head = NULL;   


void insert(char new_data) { 
   Node *node1;
   node1 = new Node; 
   node1->data = new_data; 
   node1->next = NULL; 
   head = node1; 
} 


void display() {
  Node *n;
   n = head;
   while (n != NULL) { 
      cout<< n->data <<"  "; 
      n = n->next; 
   } 
} 
int main() { 

  insert('c');
   
   
   cout<<"The linked list become: ";
   display(); 
  return 0; 
}
