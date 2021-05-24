//Height of a binary tree
//Height of a tree can also be defined as the depth of its bottommost node
//Approach: To find height of left subtree and right tree,pick the maximum out of these both and then add 1 to it
//MAX(Left Height,Right Height)+1
#include<iostream>
using namespace std;

struct Node* (int val)
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
int calcHeight(Node* root)
{if(root==NULL)
{
    return 0;
}
    int lheight=calcHeight(root->left);
    int rheight=calcHeight(root->right);
    return max(lheight,rheight)+1;
}
int main()
{
 Node* root=new Node(1);
    root->left =new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left =new Node(6);
    root->right->right =new Node(7);
    cout<<calcHeight(root)<<endl;
    return 0;
}