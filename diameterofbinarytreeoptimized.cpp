//cpp program to calculate diameter of binary tree using optimized approach
//Here we are not writing the height function in order to reduce complexity of the program
#include<iostream>
using namespace std;
struct Node(Node* root)
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
int calcdiameter(Node* root, int* height)
{if(root==NULL)
{
    *height=0;
    return 0;
}
int lh=0,rh=0;
int lDiameter=calcdiameter(root->left, &lh);
int rDiameter=calcdiameter(root->right, &rh);
int currdiameter=lh+rh+1;
*height=max(lh,rh)+1;//this is for calculating the current height   
retun max(currdiameter,max(lDiameter,rDiameter));
}

int main()
{Node* root=new Node(1);
    root->left =new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left =new Node(6);
    root->right->right =new Node(7);
    int height=0;

    cout<<calcdiameter(root,height)<<endl;
    return 0;

}