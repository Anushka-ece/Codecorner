#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>&a,int n,int i)
{
    int maxidx=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[maxidx])
    maxidx=l;
    if(r<n && a[r]>a[maxidx])
    maxidx=r;
    //we will swap the value of two nodes when value of parent node is not greater than the child node to convert it into a maxheap
    if(maxidx!=i)//this condition is used to check that if the value of maxidx has been updated then,we will swap those values
    {
        swap(a[i],a[maxidx]);
        heapify(a,n,maxidx);//applying heapify function recursively
    }

}

void heapsort(vector<int>&a)
{int n=a.size();
for(int i=n/2-1;i>0;i--)//index of first non leaf node is (n/2)-1
{
    heapify(a,n,i);//this is done to convert it into a max heap and we will convert whole tree into a maxheap this way by start traversing from the last non leaf node
}
//next step is to take the last element of the tree and swap it wit the node as root node of the entire tree 
//after swapping we will make it into a max heap and then again repeat the first step and again repeat second step
for(int i=n-1;i>0;i--)
{
    swap(a[0],a[i]);
    heapify(a,i,0);//heapify upto i and starting index is 0
}
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}