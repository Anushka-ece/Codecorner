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
//Now when we have to add an element 3 at the ned of the linked list
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
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
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
bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
node* reverse(node* &head)
{//now we have to take three pointers which are as follows:-
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL)
    {
        nextptr=currptr->next;//It will keep on moving the currptr to the next pointer
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;

    }
    return prevptr;//we have returned it here because it s new head of the reversed array
}

int main()
{
node* head=NULL;//we have created a head and at present it has NULL value
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
display(head);

node* newhead=reverse(head);//we have to create a node for storing new head here
display(newhead);
return 0;
}


