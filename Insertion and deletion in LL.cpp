#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class DLL
{
    node *head;
    node *tail;
public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int);
    void display();
    void delete_first();
    void delete_last();
    void delete_specific(int);
};

void DLL::insert(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void DLL::display()
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DLL::delete_first()
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void DLL::delete_last()
{
    node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

void DLL::delete_specific(int x)
{
    node *temp = head;
    while(temp->data != x)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

int main()
{
    DLL d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    d.insert(4);
    d.insert(5);
    d.display();
    d.delete_first();
    d.display();
    d.delete_last();
    d.display();
    d.delete_specific(3);
    d.display();
    return 0;
}
