#include<bits/stdc++.h>
using namespace std;
int countPath(int s,int e)  //s is starting point and e is ending point
{
    if(s==e)
    return 1;
    if(s>e)
    return 0;

    int count=0;
    for(int i=1;i<=6;i++)//we have taken limits from 1 to 6 as possibilities of dice exists in this range
    {
        count+=countPath(s+i,e);//i is the value of outcome of dice and starting point 
                          //will get incremented as per the outcome of dice
        
    }
    return count;
}
int main()
{
    cout<<countPath(0,3);
    return 0;
}