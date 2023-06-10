#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
  // struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
  Node *p;
  p=new Node;
   p->data = val;
	if(top==NULL){
		p->next= NULL;
		top=p;
	}else
	{
		p->next=top;
		top=p;
	}
}
void pop() {
	Node *ptr;
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
	ptr=top;
	top = top->next;
      delete ptr;
   }
}
void display() {
	Node *temp = top;
	while (temp!=NULL){
		cout<<temp->data<<endl;
		temp= temp->next;
	}
   }
   
   void peek(){
   	cout<<top->data;
   }
int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Display peek"<<endl;
   cout<<"5)Exit"<<endl;
   do {
      cout<<"Enter choice: ";
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            cout<<endl;
            break;
         }
         case 4: {
            cout<<"Display Peek"<<endl;
            peek();
            break;
         }
         case 5: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=5);
   return 0;
}
