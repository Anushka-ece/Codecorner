//Ques- Given an integer array nums,print an array answer such that answer[i] is equal to the 
//product of all the elements of nums except nums[i]
//You must write an algorithm without using the division operation

//Solution approach:To perform operation on the original array,we will take two arrays,left array
// and right array . 
//Example: Take the input array as : 1 2 3 4,right array will store the product of right elements of that array
//                     Right array: 24 12 4 1
//                      Left array: 1 1 2 6
//Final answer will be the product of individual elements of left array and right array
//Final answer: 24 12 8 6


#include<iostream>
#include<vector>
using namespace std;
int main()
{int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
  int left[n];
  int right[n];
  right[n-1]=1;//as for the last element of the array,rightmost element will be considered as 1
  for(int i=n-2;i>=0;i--)
{
    right[i]=right[i+1]*arr[i+!];
}
left[0]=1;
for(int i=1;i<n;i++)
{
left[i]=left[i-1]*arr[i-1];
}
for(int i=0;i<n;i++)
{
    cout<<left[i]*right[i]<<" ";
}
return 0;
}