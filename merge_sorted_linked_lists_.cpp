//MERGE TWO SORTED LINKED LISTS
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
node* merge(node* &head1,node* &head2){
     node* p1=head1;
    node* p2=head2;
    node* dummynode=new node(-1);//we haven't put * here as dummy node is a node and not a pointer
    node* p3=dummynode;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;//add p1 just next to p3 coz value of element at p1 is lesser than value of element at p2
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
 while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    } 
 return dummynode->next;//this step will return the merge sorted linked list
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
    node* newhead=merge(head1,head2);
    display(newhead);
    return 0;
}
   