#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
}
*head = NULL;
void append(int new_data)
{
	
	Node *p, *r;                
	if (head == NULL)
	{
		Node* new_node;
		new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		head = new_node;

	}
//	if(new_data==head->data ){
//		cout<<"0";
//	}
	else
	{
		p = head;
		while (p->next != NULL)
		p = p->next;

		r = new Node;
		r->data = new_data;
		r->next = NULL;
		p->next = r;
	}
}

void display()
{
		
	Node *p = head;

	cout << endl;
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
}

void deleteDuplicate(){
	
}

int main() {
	append(32);
	append(10);
	append(32);
	append(42);
	append(41);
	append(43);
	append(42);
	append(42);
	display();
	deleteDuplicate();
	system("pause");
}








