

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;

void append(int num)
{
    Node* temp, * r;                //temp = temporary 

    // if the list is empty, create first node
    if (head == NULL)
    {
        head = new Node;
        head->data = num;
        head->next = NULL;
    }
    else
    {
        // go to last node
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        // add node at the end
        r = new Node;
        r->data = num;
        r->next = NULL;
        temp->next = r;
    }
}

//node deletion based on input data

void deleteNode(int key)
{
    //first node deletion


    Node *q, * r;
    q = head;
    if (q->data == key)
    {
        head = q->next;
        delete q;
        return;
    }
    r = q;
    while (q != NULL)
    {
        if (q->data == key)
        {
            r->next = q->next;
            delete q;
            return;
        }
        r = q;
        q = q->next;
    }
    cout << "\nElement " << key << " not Found.";
}


    



void display()
{
    Node* temp3 = head;

    cout << endl;
    // traverse the entire linked list
    while (temp3 != NULL)
    {
        cout << temp3->data << "  ";
        temp3 = temp3->next;
    }
}
int main() {
    append(12);
    append(89);
    append(5000);
    append(50);
    display();
    deleteNode(5);
    cout << "linklist after deletion";
    display();
    system("pause");
}
