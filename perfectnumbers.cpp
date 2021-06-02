//Maximum perfect numbers in length subarray of length k in an array
#include<iostream>
#include<math.h>
using namespace std;

bool isperfectnumber(int n)
{
    int sum=1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {if(i==n/i)
            {
                sum+=i;
            }
            else
            {
                sum+=i+n/i;
            }
        }
    }
    if(sum==n && n!=1)
    {
        return true;
    }
    return false;
}

int maxSum(int arr[],int n,int k)
{
    if(n<k)
   { 
       cout<<"invalid values";
    return -1;
    }
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=arr[i];
    }
    int sum=res;
    for(int i=k;i<n;i++)
    {
        sum+=arr[i]-arr[i-k];//we are adding new element at last and deleting previous elements
        res=max(res,sum);
    }
    return res;
}
int maximumnumberofperfects(int arr[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(isperfectnumber(arr[i]))
        {
            arr[i]=1;
        }
        else
        {
            arr[i]=0;
        }
    }
    return maxSum(arr,n,k);
}

int main()
{int arr[]={28,2,3,6,496,99,8128,24};
int k=4;
int n=8;
cout<<maximumnumberofperfects(arr,n,k);
    return 0;
}
