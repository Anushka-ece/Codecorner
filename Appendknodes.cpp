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

int length(node *head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}
node* kappend(node* &head,int k)
{//our first step is to find out the length of the LL and therefore a functio is used for that
node* newhead;
node* newtail;
node* tail=head;
int l=length(head);
k=k%l;//this is done to tackle the cases when k>l
int count=1;//this will keep count of the position till which we have reached in our linked list
while(tail->next!=NULL)
{
    if(count==l-k)
    {
        newtail=tail;
    }
    if(count==l-k+1)
{newhead=tail;
}
tail=tail->next;
count++;
}
newtail->next=NULL;
tail->next=head;
return newhead;

}

int main()
{
node* head=NULL;
int arr[]={1,2,3,4,5,6};
for(int i=0;i<6;i++)
{
    insertattail(head,arr[i]);
}
display(head);
node* newhead=kappend(head,3);
display(newhead);
return 0;
}