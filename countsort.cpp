#include<iostream>
using namespace std;
void countsort(int arr[],int n)
{
    int k=arr[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;//this will increase the count of each appearing element
    }
    for(int i=1;i<=k;i++)//this is the loop for the modified array 
    {
        count[i]+=count[i-1];
    }
    int output[n];//an output array in which result will be stored
    for(int i=n-1;i>=0;i--)//we have started traversal from the last array 
                           //element of original array
    {
        output[--count[arr[i]]]=arr[i];//we have used predecrementer since we have to 
        //first decrement the value and have to store it later
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=output[i];
        }
}
int main()
{int arr[]={1,3,2,3,4,1,6,4,3};
countsort(arr,9);
for(int i=0;i<9;i++)
{
cout<<arr[i]<<" ";
}
return 0;
}