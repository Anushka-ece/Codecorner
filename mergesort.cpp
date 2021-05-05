#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r)//now we have two separate arrays 
                                        //from l to mid and from mid+1 to r
                                        // separately and then we have to merge
{
int n1=mid-l+1;
int n2=r-mid;
int a[n1];
int b[n2];//a and b are two temporary arrays for above defined two ranges
for(int i=0;i<n1;i++)
{
    a[i]=arr[l+i];
}
for(int i=0;i<n2;i++)
{
    b[i]=arr[mid+1+i];
}
//now we have two sorted arrays and we have to merge them and make them sorted as well
int i=0;
int j=0;
int k=l;
while(i<n1 && j<n2)//i is a pointer traversing a  array and j is a 
                   //pointer traversing b array
{
if(a[i]<b[j])
{
    arr[k]=a[i];
    i++;
    k++;
}
else{
    arr[k]=b[j];
    k++;
    j++;   
}
//now we also have to check that if limit of one of the arrays i sexhausted and that 
//of the other is not exhausted then if even one of the limits get exhausted it will 
//come out of the loop so we have to check that
while(i<n1)//we will enter this loop only when limit of j has been reached but that
//of i has not been reached
{
     arr[k]=a[i];
    i++;
    k++;
}
while(j<n2)//we will enter this loop only when limit of i has been reached but that
        //of j has not been reached
{
     arr[k]=b[j];
    k++;
    j++;
}
}

}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main()
{
    int arr[]={10,3,32,34,1};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}