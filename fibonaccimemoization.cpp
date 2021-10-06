//C++ program to find fibonacci using memoization
#include<bits/stdc++.h>
using namespace std;
//when we will use this simple recursive method,this will not produce correct output for very large numbers.
//Therefore,there will be use of memoization method

const int N=1e5+2;
const int MOD=1e9+7;
int dp[N];
int fib(int n)
{
    if(n==0)
    return 0;
    else if(n==1)//if there is only 1 number then also,that fibonacci sequence will result in 1
   return 0;
   else if(n==2)
   return 1;
   if(dp[n]!=-1)//this step shows that if dp has been calculated already,then simply return value
   {
       return dp[n];
   }
  
   dp[n]=fib(n-1)+fib(n-2);
   return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        //initialize dp table with -1
        dp[i]=-1;
    }
    cout<<fib(n);
    return 0;
}