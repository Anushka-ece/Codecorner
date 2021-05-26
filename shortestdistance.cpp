//Shortest distance between two nodes in a tree
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
Node* LCA(Node *root,int n1,int n2)//n1 and n2 are the two values for which LCA is to be found
{
    if(root==NULL)
    return NULL;
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);

    if(left!=NULL && right!=NULL)//this step will automatically give the LCA
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;//this is the condition that LCA has not been found
    }
    if(left!=NULL && right==NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
int finddistance(Node* root,int k,int dist)//k referes to the point till where distance is to be found and dist is the distance between the levels of the LCA nad node upto whih dis is to be found
{
    if(root==NULL)
    {
        return -1;//this condition shows that distance has become NULL but k has not been found yet

    }
    if(root->data==k)
    {
        return  dist;
    }
    int left=finddistance(root->left,k,dist+1);
    if(left!=-1)
    {
        return left;
    }
    return finddistance(root->right,k,dist+1);
}
int distancebetweennodes(Node *root,int n1,int n2)
{
    Node *lca=LCA(root,n1,n2);
    int d1=finddistance(LCA,n1,0);
    int d2=finddistance(LCA,n2,0);//0 is initial distance in both of these cases
    return d1+d2;
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
cout<<distancebetweennodes(root,4,5);
return 0;
}
