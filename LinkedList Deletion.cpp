#include <iostream>
using namespace std;
struct node
{
int data;
node* link;
node* prev;
};
node* head;
void LinkList(int num)
{
node* temp, * r;

if (head == NULL)
{
node *new_node;
new_node = new node;
         
new_node->data = num;
new_node->link = NULL;
new_node->prev = NULL;
head = new_node;
}
else
{
temp = head;
while (temp->link != NULL)
temp = temp->link;

r = new node;                          
r->data = num;
r->link = NULL;

temp->link = r;
r->prev = temp;
}
}
void del_FirstNode(int key)
{
    node* temp2;
    if (head->data == key) //delete first node
    {
        temp2 = head;
        head = head->link;
        head->link->prev=NULL;
        delete temp2;
    }
}
void del_SpecificNode(int key)// deletion of specific node
     {
        node* temp2;
        node* current = head;
        while (current->link != NULL)
        {
            if (current->link->data == key)
            {
                temp2 = current->link;
                current->link = temp2->link;
                temp2->link->prev=current;
                delete temp2;
                break;
               
            }
            else
                current = current->link;
        }
    }

//delete last node
void del_lastnode(int key){
node* temp3=head;
node* temp4;
while(temp3->link!=NULL)
{
temp3=temp3->link;
}
if(temp3->data==key){
temp4=temp3->prev;
temp4->link=NULL;
delete temp3;
}
}

void display() {     //traversal
node *p;
p = head;
while (p != NULL) {
cout << p->data << " ";
p = p->link;
}
}


int main()
{


LinkList(22);
LinkList(10);
LinkList(15);
LinkList(36);
    LinkList(20);  
    LinkList(16);
cout << "Elements in the linked list: ";
display();
    //del_FirstNode(22);
    //del_SpecificNode(36);
    del_lastnode(16);
    cout<<"\nElements After deletion:";
    display();
    cout<<"\n";



system("pause");
}

