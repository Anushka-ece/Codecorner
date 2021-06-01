//Number formed from subarray of size k,divisible by 3
#include<iostream>
#include<vector>
using namespace std;

void computenumberfromsubarray(vector<int>arr,int k)
{
pair<int,int>ans;//this ans is vector of two variables,both of them are of int data type
int sum=0;//var to store the sum of the elements

for(int i=0;i<k;i++)
{
    sum+=arr[i];
}
bool found=false;//this is used to check that whether we have found the desired subarray or not
if(sum%3==0)
{
    ans=make_pair(0,k-1);//this shows that a subarray with the desired requirement has been found and it will be stored in this vector from the specified starting point and upto desired end point
    found=true;
}
for(int j=k;j<arr.size();j++)
{
    if(found)//this is used to check that if answer has been already calculated or yet to be calculated
    break;
    sum+=arr[j]-arr[j-k];//this represents addition of the new element at the end and the deletion of the older element at the beginning of the previous array
    if(sum%3==0)
    {
        ans=make_pair(j-k+1,j);
        found=true;
    }
}
if(!found)
ans=make_pair(-1,0);//this represent the situation that no such subarray ,following the desired situation is existing
if(ans.first==-1)
cout<<"no such subarray exists"
else
{
    for(int i=ans.first;i<=ans.second;i++)
    {
        cout<<arr[i]<<" ";
    }
}

}

int main()
{   vector<int>arr={84,23,45,12,56,82};
int k=3;
computenumberfromsubarray(arr,k);
    return 0;
}