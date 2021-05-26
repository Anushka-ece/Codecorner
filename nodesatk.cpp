//we have to find nodes at distance k from a particular node
//Now there can be two cases here.We cann either find nodes at a distance k in subtree or we can search nodes at distance k in it's ancestors
#include<bits/stdc++.h>
using namespace std;

struct Node*(int val)
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
//case1:When we are counting nodes at distance k downwards(i.e in a subtree)
void printsubtreenodes(Node *root,int k)
{if(root==NULL || k<0)
{
    return;
}
if(k==0)//when k becomes ,this means that we have reached upto the desired node
{
    cout<<root->data<<" ";
    return;
}
printsubtreenodes(root->left,k-1);
printsubtreenodes(root->right,k-1);
}
//case 2:When we are counting nodes at distance k upwards(i.e in ancestor)
int printnodesatk(Node* root,Node* target,int k)//in this function we will find the desired distance and then print nodes using previous function which is printsubtreenodes
{
    if(root==NULL)
    return -1;
    if(root==target)
    {
        printsubtreenodes(root,k);
        return 0;
    }
    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printnodesatk(root->right,target,k)
    {
         if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    }
    return -1;
}
int main()
{
Node* root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);

root->right->left=new Node(6);
root->right->right=new Node(7);
printnodesatk(root,root->left,1);
cout<<endl;
return 0;
}