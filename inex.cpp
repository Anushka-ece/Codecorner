#include<bits/stdc++.h>
using namespace std;
int divisible(int n,int a,int b)
{
    int c1,c2,c3;
    c1=n/a;
    c2=n/b;
    c3=n/(a*b);
    return c1+c2-c3;
}
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<divisible(n,a,b)<<endl;
    return 0;
}
