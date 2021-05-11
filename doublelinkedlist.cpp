#include<iostream>
using namespace std;
class node{
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(node* &head,int val)
{
    node* n=new node(int val);
    n->next=head;
    if(head!=NULL)
   { head->prev=n;}
    head=n;
}
void insertattail(node* &head,int val)
{if(head==NULL)
{
    insertathead(head,val);
    return;
}
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=n;
    n->prev=temp;
}
void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteathead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;

}
void deletenode(int* &head,int pos)//pos is the position at which the node has to be deleted
{if(pos==1)//this is the corner case when element to be deleted is at the first position
{
    deleteathead(head);
    return;
}
    node* temp=head;
    int count=1;//this will keep on getting incremented till we reach the position of the node that has to be deleted
    while(temp!=NULL && count!=pos)
    {
temp=temp->next;
count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)//this is one of the corner cases when element that has to be deleted is the last element in the linked list
   { temp->next->prev=temp->prev;
   }//these steps are done to ensure that relinking of nodes after deletion takes place
    delete temp;//here temp is the node that has to be deleted 
}

int main()
{node* head=NULL;
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);

display(head);
insertathead(head,5);
display(head);
deletenode(head,5);
display(head);
return 0;

}