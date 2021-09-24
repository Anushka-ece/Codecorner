//ROTATE A LINKED LIST K  TIMES IN COUNTER CLOCKWISE DIRECTIONS
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class node
{
    int data;
    node* next;
    node(int val)
    {
        data=val;
    next=NULL;
    }
}

void rotatenodes(node **headref,int k)
{
    if(k==0)//when k become equals to zero,it will be returned directly
    return;
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.

    node* curr=*headref;//stores the value at head pointer initially

    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.

    int count=1;//initialize the value of count as 1
    while(count<k && curr!=NULL)//running a loop till the time k operations get coplete here and pointer won't become NULL
    //this step is done to find the kth element
    {
curr=curr->next;
count++;
    }
    
    // If current is NULL, k is greater than
    // or equal to count of nodes in linked list.
    // Don't change the list in this case
    if(curr==NULL)
    return;

    node* kthnode=curr;//since,curr stores the value of kth node,store this kth node's value in a node variable named kthnode

     // current will point to
    // last node after this loop
    // current will point to
    // node 60 in the above example
    while(curr->next!=NULL)
    curr=curr->next;

    curr->next=*headref;//at this point,curr is pointing to last node,hence change the pointer of element next to curr to headref
    *headref=kthnode->next;//new head is headref,which is next to the kth node
    kthnode->next=NULL;

}
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main(void)
{
    /* Start with the empty list */
    Node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    rotate(&head, 4);
 
    cout << "\nRotated Linked list \n";
    printList(head);
 
    return (0);
}