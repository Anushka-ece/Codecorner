#include<iostream>
#include<vector>
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
vector<Node*>construct_trees(int start,int end)//start and end are the values that we are going to store at nodes as data
{
vector<Node*>trees;
if(start>end)
{
    trees.push_back(NULL);
    return trees;
}
for(int i=start;i<=end;i++)
{vector<Node*>leftsubtree=construct_trees(start,i-1);//i-1 is here as left subtree has all nodes lesser than ith node
vector<Node*>rightsubtree=construct_trees(i+1,end);

for(int j=0;j<leftsubtree.size();j++)//with the help of these loops, we are combining all possible subtrees of left with all possible right subtrees
{Node* left=leftsubtree[j];
    for(int k=0;k<rightsubtree.size();k++)
    {
Node* right=rightsubtree[k];
Node* node=new Node(i);
node->left=left;
node->right=right;
trees.push_back(node);
    }
}
} 
return trees;
}
void preorder(Node* root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
int main()
{
    vector<Node*>totaltrees=construct_trees(1,3);
    for(int i=0;i<totaltrees.size();i++)
    {
        cout<<(i+1)<<":";
        cout<<endl;
    }
    return 0;
}