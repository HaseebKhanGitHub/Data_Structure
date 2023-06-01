
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void display(const node *head)
{
   while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node *dataelement(int value){

int x;
node *head=NULL;
node *tail=NULL;

for(int i=0;i<value;i++)
{
    cin>>x;
    node *value=new node(x);
        if(head==NULL)
        {
            head=value;
            tail=value;
        }

    else
    {
        tail->next=value;
        tail=tail->next;

    }

}
return head;
}


void Delete_Duplicates(node *start)
{
    node *ptr_1, *ptr_2, *duplicate;
    ptr_1 = start;
    while (ptr_1 != NULL && ptr_1->next != NULL)
    {
        ptr_2 = ptr_1;

        
        while (ptr_2->next != NULL)
        {
            if (ptr_1->data == ptr_2->next->data)
            {
                duplicate = ptr_2->next;
                ptr_2->next = ptr_2->next->next;
                delete(duplicate);
            }
            else 
                ptr_2 = ptr_2->next;
        }
        ptr_1 = ptr_1->next;
    }
}
int main()
{
    int value;
    cout<<"ENTER RANGE : "<<endl;
    cin>>value;
    cout<<"ENTER ELEMENTS: "<<endl;
    node *head=dataelement(value);
    cout<<"LINKEDLIST AFTER DELETING DUPLICATES BECOMES : "<<endl;
   Delete_Duplicates(head);
    display(head);
}
