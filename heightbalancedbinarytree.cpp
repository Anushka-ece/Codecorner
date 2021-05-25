//Balanced height in a binary tree
#include<bits/stdc++.h>
#include<iostream>
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
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight>rheight)
    return (lheight+1);
    else if(rheight>lheight)
    return (rheight+1);

}
bool isbalanced(Node* root)
{if(root==NULL)//this is the base condition and this will be reached when there will be no node left in the tree and hence true is returned
{
    return true;
}
    if(isbalanced(root->left)==false)//this will sjow that there is at least one node of the left subtree of the current node that is not balanced
    {
return false;
    }
    if( isbalanced(root->right)==false)
    {
        return false;
    }
    //now we have to check that whether the node on which we are present right now is balanced or not
    int lh=height(root->left);//this will find out the height of the left child
    int rh=height(root->right);
    if(abs(lh-rh)<=1)//this shows that if the absolute difference of the height of the left node and right node is less than equal to 1 or not
    return true;
    else
    return false;
}
int main()
{
Node* root1=new Node(1);
root1->left=new Node(2);
root1->right=new Node(3);
root1->left->left=new Node(4);
root1->left->right=new Node(5);
root1->right->left=new Node(6);
root1->right->right=new Node(7);

if(isbalanced(root1))
cout<<"balanced tree";
else
cout<<"unbalanced tree";
}