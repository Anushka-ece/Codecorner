//C++ program to find minimum number of squares of numbers whose sum is equal to given number 
#include<iostream>
#include<map>
using namespace std;
const int N=1e3+2,MOD=1e9+7;
int minsquare(int n)
{
    if(n==1 || n==2 || n==3 || n==0)//base condition
    return n;
    int ans=MOD;//here since we have to minimise the number of squares,we need to initialize
    //ans with a very large value
    for(int i=1;i*i<=n;i++)
    {
      ans=min(ans,1+minsquare(n-i*i));  
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<minsquare(n)<<endl;
    return 0;
}