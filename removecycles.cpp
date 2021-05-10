#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* next;//pointer pointing to the next
    node(int val)//it is a constructor
    {
        data=val;
        next=NULL;
    }
    
};
void insertattail(node* &head,int val)
{
    node* n= new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){//while next of temp becomes NULL then we reach to the ned of the array
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head)
{
    node*temp=head;
    while(temp!=NULL)//temp=NULL shows that we have reached to the end of linked list
    {
cout<<temp->data<<"->";
temp=temp->next;
    }
    cout<<endl;
}
void makecycle(node* &head,int pos)//function for making cycle in a linked list
{
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

    
bool detectcycle(node* &head)
{
    node* slow=head;
    node* fast=head;//both slow and fast pointers have been initialized from head
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;//slow pointer will move 1 step forward
        fast=fast->next->next;//fast pointer will move 2 steps forward
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
void removecycle(node* &head)
{
     node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next)
    {
slow=slow->next;
fast=fast->next;
    }
slow->next=NULL;
}
int main()
{
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
insertattail(head,6);
makecycle(head,3);
//display(head);
cout<<detectcycle(head)<<endl;
removecycle(head);
cout<<deletecycle(head)<<endl;
display(head);
return 0;
}