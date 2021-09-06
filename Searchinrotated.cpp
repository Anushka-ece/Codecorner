//Search an element in a rotated array
#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l,int h,int key)
{
    if(l>h)
    return -1;
    int mid=(l+h)/2;
    if(arr[mid]==key)
    return mid;
    if(arr[l]<=arr[mid])//if left half of the array is sorted
    {
        if(key>=arr[l] && key<=arr[mid])
        {
            return search(arr,l,mid-1,key);
        }
        return search(arr,mid+1,h,key);
    }//else if the right half will be sorted if left one was not sorted
    if(key>=arr[mid] && key<=arr[h])
    return search(arr,mid+1,h,key);
    return search(arr,l,mid-1,key);
}
int main()
{
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int index=search(arr,0,n-1,key);
    if(index==-1)
    cout<<"key found"<<endl;
    else
    cout<<"key is found at : "<<index<<endl;
    return 0;
}