//Find lowest common ancestor of a node in a binary tree
#include<iostream>
#include<vector>
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

bool getPath(Node* root,int key,vector<int>&path)
{if(root==NULL)//this is the condition that we are trying to access children of leaf node and here we simply cannot find our key
return false;
    path.push_back(root->data);
    if(root->data==key)
    return true;
    if(getPath(root->left,key,path)|| getPath(root->right,key,path))//we are checking that whether key exists in left or right subtree or not
    {
        return true;
    }
    path.pop_back();//we have popped the root data as if we are not able to found key upto now that means we are on the wrong path and have to try another one
    return false;
}
int LCA(Node* root,int n1,int n2)//n1 and n2 are the two nodes for which LCA is to be found
{vector<int>path1,path2;//these vectors will store the path of both of the nodes
if(!getPath(root,n1,path1) || !getPath(root,n2,path2))//here getpath function will return values in boolean to check whether a path exists between root and desired node or not and if anyone of the path does not exist then there will be no possibility to find out the LCA
{
    return -1;
}
int pc;//this is the path change variable
for(int pc=0;pc<path1.size() && path2.size();pc++)
{
    if(path1[pc]!=path2[pc])
    {
        break;
    }

}
return path1[pc-1];
}

//another function to find LCA to avoid using getPath function to reduce complexity
Node* LCA2(Node* root,int n2,int n1)
{if(root==NULL)
return NULL;
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* leftLCA=LCA2(root->left,n2,n1);
    Node* rightLCA=LCA2(root->right,n2,n1);

    if(leftLCA && rightLCA)//this shows that both leftLCA and rightLCA are valid and not NULL and either of n1 and n2 might exist in any one of them
    {
        return root;
    }
    if(leftLCA!=NULL)
    {
        return leftLCA;
    }
    return rightLCA;
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
int n1=7;
int n2=6;
/*int lca=LCA(root,n1,n2); this is for checking through method 1
if(lca==-1)
{
    cout<<"lca not exist";
}
else
{
    cout<<"LCA"<<" "<<lca<<endl;
}*/
Node* lca=LCA2(root,n2,n1);
if(lca==NULL)
{
    cout<<"LCA doesn't exist"<<endl;
}
else
{
    cout<<"LCA : "<<lca->data<<endl;
}
return 0;
}