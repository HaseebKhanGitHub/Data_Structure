#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* getNode(int data)
{
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void reverse(Node** head_ref)
{
	if (*head_ref == NULL)
		return;

	Node* prev = NULL;
	Node* current = *head_ref;
	Node* next;
	do {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	} while (current != (*head_ref));

	(*head_ref)->next = prev;
	*head_ref = prev;
}

void printList(Node* head)
{
	if (head == NULL)
		return;

	Node* temp = head;
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}

int main()
{
	
	Node* head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->next->next->next = getNode(4);
	head->next->next->next->next = head;

	cout << "Given circular linked list: ";
	printList(head);

	reverse(&head);

	cout << "\nReversed circular linked list: ";
	printList(head);

	return 0;
}
