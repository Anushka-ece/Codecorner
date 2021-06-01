//Find a maximum sum subarray of size k and sum<x using sliding window challenge
#include<iostream>
using namespace std;
void maxsubarraysum(int arr[],int n,int k,int x)
{int sum=0;
int ans=0;
for(int i=0;i<k;i++)
{
    sum+=arr[i];
}
if(sum<x)
{
    ans=sum;
}
for(int i=k;i<n;i++)
{
    sum-=arr[i-k];//here we are removing the first value of the previous subarray of k elements
    sum+=arr[i];
    //here we are adding a new element
    if(sum<x)
    {
        ans=max(ans,sum);
    }
}
cout<<ans;

}

int main()
{int arr[]={7,5,4,6,8,9};
int k=3;

int x=20;
int n=6;
maxsubarraysum(arr,n,k,x);
    return 0;
}
