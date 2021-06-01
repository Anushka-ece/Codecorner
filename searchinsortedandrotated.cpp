//BINARY SEARCH CHALLENGE 4
#include<iostream>
using namespace std;
//we are going to solve this problem using recursive approach and going to check recursively that whether key has been found or not

int searchinrotatedarray(int arr[],int key,int left,int right)//left and right here defines the extremities of the binary search
{
if (left>right)
{
    return -1;
}
int mid = (left+right)/2;
if(arr[mid]==key)
{
    return mid;
}
if(arr[left]<=arr[mid])//this step is used to check whether there has been rotation in this part or not
{
    if(key>=arr[left] && key<=arr[mid])
    {
        searchinrotatedarray(arr,key,left,mid-1);
    }
    searchinrotatedarray(arr,key,mid+1,right);//this will return answer of the right half
}
if(key>=arr[mid] && key<=arr[right])
{
    return searchinrotatedarray(arr,key,mid+1,right);
}
return searchinrotatedarray(arr,key,left,mid-1);
}

int main()
{
    int arr[]={6,7,8,9,10,1,2,5};
    int n=8;
    int key=8;
    int idx=searchinrotatedarray(arr,key,0,n-1);
if(idx==-1)
cout<<"key does not exists";
else
cout<"key exists and is at idx: " << idx;
cout<<endl;
    return 0;
}