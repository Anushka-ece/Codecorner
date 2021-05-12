//FIND THE INTERSECTION POINT OF TWO LINKED LISTS
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

int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
void intersect(node* &head1,node* &head2,int pos)//in this function at the ned of head2 ,head1 is getting added
{
node* temp1=head1;
pos--;
while(pos--)
{
    temp1=temp1->next;
}
node* temp2=head2;
while(temp2->next!=NULL){
    temp2=temp2->next;
}
temp2->next=temp1;
}
int intersection(node* &head1,node* &head2)
{int l1=length(head1);
int l2=length(head2);
int d=0;
node* ptr1;//here we are pointing ptr1 to the ll which is of more length
node* ptr2;
if(l1>l2)
{
    d=l1-l2;
    ptr1=head1;
    ptr2=head2;
}
else{

    d=l2-l1;
    ptr1=head2;
    ptr2=head1;
}
while(d)//in this value we will keep on decrementing the value of d and will come out of the loop as soon as it will becime equal to 0
{//this step is done to start ptr1 and ptr2 from same number of positions before the intersection point
ptr1=ptr1->next;//we will keep on increasing the value of pointer 1
if(ptr1==NULL)
{
    return -1;//if ptr 1 become equal to 1 on getting decreased then return -1 in that case as intersection is not possible in that case
}
d--;
}
while(ptr1!=NULL && ptr2!=NULL)//we will keep on incrementing values of ptr1 and ptr2 till the time both of them not become null
{if(ptr1==ptr2)
{
    return ptr1->data;//this shows that if there comes a point when value of pointer 1 become equals to the value of pointer 2 then we can return the value of data of anyof the two pointers.But if it is not so then we will increment ptr1 and ptr2
}
    ptr1=ptr1->next;
    ptr2=ptr2->next;

}
return -1;//if no intersection point is found

}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertattail(head1,1);
    insertattail(head1,2);
    insertattail(head1,3);
    insertattail(head1,4);
    insertattail(head1,5);
    insertattail(head1,6);
    insertattail(head2,9);
    insertattail(head2,10);
    intersect(head1,head2,3); //a function to create intersection is also  made above
    display(head1);
    display(head2);
    cout<<intersection(head1,head2)<<endl;
    return 0;
}