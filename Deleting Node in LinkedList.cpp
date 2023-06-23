#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};
Node *head;

void append(int num){
	Node *temp,*r;
	 if (head == NULL)
    {
        head = new Node;
        head->data = num;
        head->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        r = new Node;
        r->data = num;
        r->next = NULL;
        temp->next = r;
    }
}

void delnode(int key){
	Node *t;
	if(head->data==key){
		t=head;
		head = head->next;
		delete t;
		
	}
	else {
		Node *c = head;
		while(c!=NULL){
			if(c->next->data==key){
				t=c->next;
				c->next=t->next;
				delete t;
				break;
			}
			else
			c=c->next;
		}
	}
}
void display()
{
    Node* temp3 = head;

    cout << endl;
    while (temp3 != NULL)
    {
        cout << temp3->data << "  ";
        temp3 = temp3->next;
    }
}

int main(){
	append(12);
	append(122);
	append(45);
	display();
	delnode(122);
	display();

}




