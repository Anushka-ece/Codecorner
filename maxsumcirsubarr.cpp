

#include <bits/stdc++.h>

using namespace std;
int kadane(int arr[],int n)
{
    int current_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        if(current_sum<0){
            current_sum=0;
        }
        max_sum=max(max_sum,current_sum);
    }
    return max_sum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int wrapsum,nonwrapsum;
    nonwrapsum=kadane(arr,n);
    int totalsum=0;
    for(int i=0;i<n;i++)
    {
        totalsum+=arr[i];
        arr[i]=-arr[i];
    }
    wrapsum= totalsum+kadane(arr,n);
    cout<<max(wrapsum,nonwrapsum);

    return 0;
}