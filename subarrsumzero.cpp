//Count subarrays with sum equals to zero:solve using hashing technique
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,int>cnt;
    int prefsum=0;//this will calculate the sum of all the elements upto element at ith position
    for(int i=0;i<n;i++)
    {
        prefsum+=a[i];
        cnt[prefsum]++;
    }
    int ans=0;
    map<int,int>::iterator it
    for(it=cnt.begin();it!=cnt.end();it++)
    {int c=it->second;
    ans+=(c*(c-1))/2;//this is the application of the combination formula here
if(it->first==0)//first is the key value in it and here it has been checked that if the occurence of 0 is there ,then it means that sum has become 0 upto this point
{
    ans+=it->second;
}
    }

    return 0;
}