//In this question,we will use the approach that we will find node value first,then max path through left child + node val,then max path through right child + node val and at last max path through left child+right child+node val
#include<bits/stdc++.h>
using namespace std;
struct Node{
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

int maxpathsumutil(Node* root,int &ans)
{
    if(root==NULL)
    return 0;
    int left=maxpathsumutil(root->left,ans);
    int right=maxpathsumutil(root->right,ans);
    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodemax);

    //now we have to consider a case when maximum path is going through root
    int singlepathsum=max(root->data,max(root->data+right,root->data+left));
    return singlepathsum;

}
int maxpathsum(Node* root)
{
    int ans=INT_MIN;
maxpathsumutil(root,ans);//this is a recursive function which will go recursively to all the four values that we have discussed in the comment above and compare it with ans finally
    return ans;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
root->left->left=new Node(4);
root->right->left=new Node(5);
cout<<maxpathsum(root);
return 0;
}
