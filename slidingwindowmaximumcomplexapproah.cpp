//Sliding Window Maximum Using Deque using o(nlogn) approach
#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);//this will declare the array dynamically
    for(auto &i:a)
    {
        cin>>a;
    }
    multiset<int,greater<int>>s;//greater<int> is used to obtain maximum elemnt at the top
    vector<int>ans;//array to store answers
    for(int i=0;i<k;i++)
    {
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());//this step will return element at the top and we have used gretaer<int> already to obtain maximum value element at the top
    for(int i=k;i<n;i++)//this is the iteration for rest of the arrays
    {
s.erase(s.lower_bound(a[i-x]));//this tep is done to erase the element that has already been used
s.insert(a[i]);
ans.push_back(*s.begin());
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }


}
