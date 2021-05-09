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
void deletion(node* &head,int val)//val is the value present in the linked list 
//that has to be removed
{if(head==NULL)//this is the case when linked list is empty
{
    return;
}
if(head->next==NULL)//It is the case when there is only a single element in the entire linked list
{
    deleteathead(head);
    return ;
}
    node* temp=head;
    while(temp->next->data!=val){// As we know that for removing nth node,we have
    // to change (n-1)th node so our aim is to search(n-1)th node and not (n)th node
    //and the while loop says that this loop will operate till data of node next to temp
    // node not become equal to val
        temp=temp->next;//thiswill perform increment in temp and here it will stop when
        // we will reach to n-1 th node
    }
    node* todelete=temp->next;//it is the node that has to be deleted
    temp->next=temp->next->next;//Here,we are updating the link of the n-1 th node as temp->next 
    //points to the value that has to be deleted and temp->next->next denotes the new location 
    //where n-1 th node is pointing after successful deletion
    delete todelete;
}
void deleteathead(node* &head)//This is the code for removing the element at the head as it is a special case
//it has no val as value to be deleted is already specified and is at head
{node* todelete=head;
head=head->next;
delete todelete;

}


int main()
{
node* head=NULL;//we have created a head and at present it has NULL value
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
//display(head);
insertattail(head,4);
display(head);
//cout<<search(head,5)<<endl;
//deletion(head,3);
deleteathead(head);
display(head);
return 0;
}


