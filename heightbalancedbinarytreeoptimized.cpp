//Balance a binary tree using optimized approach
//In the previous approach,we were also using height function which made the complexity equal to o(n^2) ,but we need to decrease complexity and jence using this approach
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

bool isbalanced(Node* root,int height)//we are passing height pointer here to check height at each node
{if(root==NULL)
return true;

int lh=0,rh=0;//we have created variables for storing height of left node and right node
if(isbalanced(root->left,&lh)==false)
{
    return false;
}
if(isbalanced(root->right,&rh)==false)
{
    return false;
}
*height=max(lh,rh)+1;//this is the current height
if(abs(lh-rh)<=1)//this step is done to check that whether node is balanced at this point or not 
{
    return true;
}
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

int height=0;
if(isbalanced(root1,&height)==true)
cout<<"balanced tree";
else
cout<<"unbalanced tree";
}