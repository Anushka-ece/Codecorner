//DETECT STARTING POINT OF LOOP IN LINKED LIST
#include<iostream>
using namespace std;

int main()
{node* slow=head;
node* fast=head;
while(slow!=NULL && fast!=NULL && fast->next!=NULL)
{
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)//this shows that it has cycle
    {
        break;
    }
}
if(slow!=fast)
return NULL;//this is the condition when no loop will exist
 fast=head;
 while(slow!=fast)
 {
     slow=slow->next;
     fast=fast->next;
 }
 return fast;

    
}