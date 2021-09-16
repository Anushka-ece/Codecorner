//check if a linked list is a pallindrome or not
Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
   fast=fast->next->next;
    }//upto this step we have decided to find the middle element
    Node* prev=NULL;
    Node* next;
    Node* curr=slow;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }//upto this step,we have reversed the linked list
    //now,prev pointer is at the end of the list and head pointer is at the first element of the list
    fast=head;
    while(prev!=NULL)
    {
    if(fast->data!=prev->data)
    return false;
    fast=fast->next;
    prev=prev->next;
    }
    return true;
}