//Ques - Given an integer array nums and an integer k, return the kth largest element in the array
//Example - Input: 3 2 1 5 6 4  K=2
//          Output: 5 (as it is the second largest element in the array)
//NAIVE APPROACH

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
for(int i=0;i<n-1;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]>arr[i])
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
}
cout<<arr[k-1];
return 0;
}
