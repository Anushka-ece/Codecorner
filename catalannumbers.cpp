#include<iostream>
using namespace std;
int catalan(int n)
{int res=0;//in this res variable,we will get our nth value stored
if(n<=1)
return 1;
    for(int i=0;i<n;i++)
    {
res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<catalan(i)<<" ";
}
cout<<endl;
return 0;
}