//Two nodes of a BST are swapped.Our task is to restore the correct BST
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void calcpointer(Node* root,Node** first,Node** mid,Node** last,Node** prev)//in this function we will basically traverse tree in an inorder fashion and then calculate values of pointers
{
    if(root==NULL)
    return;
    calcpointer(root->left,first,mid,last,prev);
    //now we have to check first that whether this dissruption in order has happened for the first time or not
    if(*prev && root->data<(*prev)->data)//this shows that previous exists already and root's data is lesser than previous data
    {if(!*first)//this is the condition of first violation
    {
        *first=*prev;
        *mid=root;
    }
    else//second case of violation
    {
*last=root;//this is only for case 1
    }

    }
    *prev=root;//this will go in right subtree
    calcpointer(root->right,first,mid,last,prev);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void restoreBST(Node* root)
{
    Node* first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    calcpointer(root,&first,&mid,&last,&prev);
    //case1:
    if(first && last)
    {
        swap(&(first->data),&(last->data));
    }
    else if(first && mid)
    {
        swap(&(first->data),&(mid->data));
    }

}
void inorder(Node* root)
{if(root==NULL)
return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
int main()
{Node* root=new Node(6);
root->left=new Node(9);
root->right=new Node(3);
root->left->left=new Node(1);
root->left->right=new Node(4);
root->right->right=new Node(13);
inorder(root);
cout<<endl;
restoreBST(root);
cout<<endl;
inorder(root);
cout<<endl;

return 0;
}






