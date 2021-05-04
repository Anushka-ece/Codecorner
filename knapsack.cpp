#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,int n,int wt[],int value[])
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]>W)
    {
        return  knapsack(W,n-1,wt,value);
    }
    return max(knapsack(W,n-1,wt,value),value[n-1]+knapsack(W-wt[n-1],n-1,wt,value));
}
int main()
{int wt[]={10,20,30};
int value[]={100,50,150};
int W=50;
cout<<knapsack(W,3,wt,value)<<endl;
return 0;

}