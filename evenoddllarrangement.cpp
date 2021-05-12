//PUT EVEN INDEXED ELEMENTS AFTER ODD INDEXED ELEMENTS IN LINKED LIST
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
void evenafterodd(node* &head)
{
    node* odd=head;
    node* even=head->next;
    node* evenstart;//this pointer is used to keep a record of position of the even node
    while(odd->next!=NULL && even->next!=NULL)
    {
odd->next=even->next;//this step is done to ensure that all odd indexed elements are together
odd=odd->next;
even->next=odd->next;
even=even->next;
    }
    odd->next=evenstart;//here we will put evenstart as the next element to the odd
    if(odd->next!=NULL)
    {
        even->next=NULL;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++)
    {
        inserattail(head,arr[i]);
    }
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}