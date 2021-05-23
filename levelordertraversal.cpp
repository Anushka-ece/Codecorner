//To traverse level one by one from top
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

void printlevelorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;//a queue is made to store root pointer
    q.push(root);
    q.push(NULL);//this NULL will be pushed after completion of printing of nodes at each level as it is an indiactor for representing that
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();//node is popped before analyzing
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left)//this is the condition to check if the left child of node is NULL or not and if it is not NULL then it will aslo get pushed into the output
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        q.push(NULL);
    }
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
    printlevelorder(root);

}