#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
signed main()
{
int n;
cin>>n;//no. of denominations
vector<int>a(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int x;
cin>>x;
sort(a.begin(),a.end(),greater<int>());//we have added third argument here,as we have to maintain decreasing order
return 0;
int ans=0;
for(int i=0;i<n;i++)
{
    ans+=x/a[i];
    x-=x/a[i] *a[i];
}
cout<<ans<<endl;
return 0;
}