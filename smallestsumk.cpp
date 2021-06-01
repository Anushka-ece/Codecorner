//Find a minimum sum subarray of  sum>x using sliding window challenge
#include<iostream>
using namespace std;

int smallestsubarraywithsum(int arr[],int n,int x)
{
int sum=0;
int minlength=n+1;//length of the subarray and this is an initialized length which actually is not possible as length of the array is n at max and it is just initialized to comapare with other lengths
int start=0;
int end=0;
while(end<n)
{
    while(sum<=x && end<n)
    {
        sum+=arr[end++];
    }
    while(sum>x && end<n)
    {
        if(end-start < minlength)//this shows that if current subarray size is lesser than already existing answer
        {
            minlength=end-start;
        }
        sum-=arr[start++];
    }
}
return minlength;
}


int main()
{
int arr[]={1,4,45,6,10,19};
int x=51;
int n=6;
int minlength=smallestsubarraywithsum(arr,n,x);
if(minlength==n-1)
{
    cout<<"no such subarray exists"<<endl;

}
else
{
    cout<<minlength;
}
return 0;

}