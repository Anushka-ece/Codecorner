//Sliding Window Maximum  using o(1) approach using deque
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
deque<int>q;
vector<int>ans;
for(int i=0;i<k;i++)//we have to make sure that elements of deque are in non increasing order
{
while(!q.empty() and a[q.back()]<a[i]){
    q.pop_back();
}
q.push_back(i);
}
ans.push_back(a[q.front()]);
for(int i=k;i<n;i++)//this step will push indices and not elements in queue
{
if(q.front()==i-k)
{
q.pop_front();
}
while(!q.empty() and a[q.back()]<a[i])
{
q.pop_back()
}
q.push_back(i);
ans.push_back(a[q.front()]);
}
for(auto i:ans)
{
    cout<<i<<" ";
}
return 0;
}