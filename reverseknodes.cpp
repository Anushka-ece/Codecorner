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
node* reversek(node* &head,int k)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k)//reverse operation will keep on going in linked list
    //till the time this condition keeps on getting satisfied
    {nextptr=currptr->next;//step to increase current pointer
    currptr->next=prevptr;//step to reverse pointer link
    prevptr=currptr;
    currptr=nextptr;
    count++;//till this step first k nodes will get reversed
    }
    if(nextptr!=NULL)//this is to check if there are no elements left in linked list
    {
head->next=reversek(nextptr,k);
    }
    return prevptr;
}
 int main()
{
node* head=NULL;//we have created a head and at present it has NULL value
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
insertattail(head,6);
display(head);
int k=2;
node* newhead=reversek(head,k);//we have to create a node for storing new head here
display(newhead);
return 0;
}