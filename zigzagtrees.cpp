#include<iostream>
#include<stack>
using namespace std;
struct Node
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

void zigzagtraversal(Node* root)
{if(root==NULL)
{
    return;3
}
    stack<Node*>currlevel;
    stack<Node*>nextlevel;
    bool lefttoright=true;
    currlevel.push(root);
    while(!currlevel.empty())
    {
        Node* temp=currlevel.top();
        currlevel.pop();
        if(temp)
        {
            cout<<temp->data<<" ";
        
        if(lefttoright)
        {
            if(temp->left)
            {
                nextlevel.push(temp->left);
            }
            if(temp->right)
            {
                nextlevel.push(temp->right);
            }
        }
        //right to left i.e condition when lwft to right is false
        else
        {
            if(temp->right)
            {
                nextlevel.push(temp->right);
            }
            if(temp->left)
            {
                nextlevel.push(temp->left);
            }
        }

        }
        if(currlevel.empty())
        {
            lefttoright=!lefttoright;//after finishing one level,we will change the value of lefttoright from true to false or from,false to true
            swap(currlevel,nextlevel);
        }
    }
}
int main()
{Node* root=new Node(12);
root->left=new Node(9);
root->right=new Node(15);
root->left->left=new Node(5);
root->left->right=new Node(10);
zigzagtraversal(root);
cout<<endl;
return 0;

}