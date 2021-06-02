//In an array,find a subarray of size k such that elements in that subarray form a pallindrome after concatenation
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool ispallindrome(int n)
{
    int temp=n,number=0;
    while(temp>0)
    {
        number=number*10 + temp%10;
        temp=temp/10;
    }
    if(number==n)
    return true;
    return false;
}

int findpallindromicsubarray(vector<int>arr,int k)
{
int num=0;//in this variable,we will keep on storing the num formed by each of the subarray of k length
for(int i=0;i<k;i++)
{
    num=num*10+arr[i];
}
if(ispallindrome(num))
{
    return 0;
}
for(int j=k;j<arr.size();j++)
{
num=(num%(int)pow(10,k-1))*10 + arr[i];
if(ispallindrome(num))
{
    return j-k+1;//this is the starting point of the desired subarray
}
}
return -1;
}

int main()
{vector<int>arr={2,3,5,1,1,5};
int k=4;
int ans=findpallindromicsubarray(arr,k);
if(ans==-1)
{
    cout<<"no pallindromic subarray exists";
}
else
{
    for(int i=ans;i<ans+k;i++)
    {
        cout<<arr[i]<<" ";
    }
}
    return 0;
}