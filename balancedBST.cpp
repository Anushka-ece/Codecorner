//Build a balanced BST from a sorted array
#include<iostream>
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

void preorderprint(Node* root)
{
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* sortedarraytoBST(int arr[],int start,int mid)
{
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=sortedarraytoBST(arr,start,mid-1);
    root->right=sortedarraytoBST(arr,mid+1,end);
    return root;

}
int main()
{int arr[]={10,20,30,40,50};
Node* root=sortedarraytoBST(arr,0,4);
preorderprint(root);
cout<<endl;
    return 0;
}