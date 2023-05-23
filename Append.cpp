#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
}
*head = NULL;
void append(int new_data)
{
	Node* temp, *r;                //temp = temporary 

	// if the list is empty, create first node
	if (head == NULL)
	{
		Node* new_node;
		new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		head = new_node;

	}
	else
	{
		// go to last node
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		// add node at the end
		r = new Node;
		r->data = new_data;
		r->next = NULL;
		temp->next = r;
	}
}
void display()
{
	Node *temp = head;

	cout << endl;
	// traverse the entire linked list
	while (temp != NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}
int main() {
	append(12);
	append(89);
	append(5000);
	append(50);
	display();
	system("pause");
}
