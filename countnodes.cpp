//count all the nodes in a binary tree\
//For every node we can count nodes number as left subtree count+right subtree count+1..this 1 is added to add the current node
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
7

int countnodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
return countnodes(root->left)+countnodes(root->right)+1;
}
int main()
{
    Node* root=new Node(1);
    root->left =new Node(2);
    root->right=new Node(3);
    root->left->left =new Node(4);
    root->left->right =new Node(5);
    root->right->left =new Node(6);
    root->right->right =new Node(7);
    cout<<countnodes(root)<<endl;
    return 0;

}