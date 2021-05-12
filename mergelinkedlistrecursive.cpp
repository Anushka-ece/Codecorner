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
node* mergerecursive(node* &head1,node* &head2)
{
    if(head1==NULL){
        return head2;
    }
 if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergerecursive(head1->next,head2);
    }
    else
    {
        result=head2;
        result->next=mergerecursive(head1,head2->next);
    }
    return result;
}
int main()
{
    node* head1=NULL;
    node* head2=NULL;
    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};
    for(int i=0;i<4;i++)
    {
        insertattail(head1,arr1[i]);
    }
for(int i=0;i<3;i++)
    {
        insertattail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newhead=mergerecursive(head1,head2);
    display(newhead);
    return 0;
}