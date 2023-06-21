#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node *Prev;
		Node *Next;
};

int main(){
	Node *head;
	Node *one = NULL;
	Node *two = NULL;
	Node *third = NULL;
	
	one=new Node();
	two=new Node();
	third=new Node();
	
	one->data=1;
	one->Prev=NULL;
	one->Next=two;
	
	two->data=2;
	two->Prev=one;
	two->Next=third;
	
	third->data=3;
	third->Prev=two;
	third->Next=NULL;
	
	head = one;
	while(head!=NULL){
		cout<<head->data;
		head = head->Next;
	}
	
}
