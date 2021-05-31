//Place elements to maximise the minimum distance
//BINARY SEARCH CHALLENGE 1
#include<iostream>
#include<algorithm>//used for sorting function
using namespace std;

bool isfeasible(int mid,int arr[],int n,int k)//the aim of this function is to chek that whether k possible vlues of numbers can be obtained from arr or not,which have distance equals to mid between them
{
int pos=arr[0],elements=1;//elements is used to check the condition when the number of elements become equal to k
for(int i=1;i<n;i++)
{
    if(arr[i]-pos>=mid)
    {
        pos=arr[i];
        elements++;
        if(elements==k)
        return true;
    }
}
return false;
}

int largestmindistance(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int result=-1;
    int left=1;
    right=arr[n-1];//now we will apply binary search operation over this entire range from left to right of array and will check the feasability one by one
    while(left<right)
    {
int mid=(left+right)/2;
if(isfeasible(mid,arr,n,k))
{
    result=max(result,mid);
    left=mid+1;//this is done to check the greater value of result than the one which was obtained in the previous step where we calculated the value of result
}
else
{
    right=mid;
}
    }
    return result;
}

int main()
{
int arr[]={1,2,8,4,9};
int n=5;
int k=3;
cout<<largestmindistance(arr,n,k);
return 0;
}