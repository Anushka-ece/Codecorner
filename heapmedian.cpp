//Find median of the running stream using heaps
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//we have to define one mkin heap and one max heap,both globally
priority_queue<int,v1,greater<int>>pqmin;
priority_queue<int,v1>pqmax;

void insert(int x)
{
    if(pqmin.size()==pqmax.size)
    {
        if(pqmax.size()==0)//if no element has been inserted yet
        {
            pqmax.push(x);
            return;
        }
        if(x<pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        //case 1 :size of max heap is greater than size of min heap
        //case 2 :size of min heap is greater than size of max heap
        if(pqmax.size()>pqmin.size())
        {
            if(x>=pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int tmp=pqmax.top();
                pqmax.pop();
                pqmin.push(tmp);
                pqmax.push(x);
            }
        }
        else{
            if(x<=pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int tmp=pqmin.top();
                pqmin.pop();
                pqmax.push(tmp);
                pqmin.push(x);
            }

        }
    }
}
double findMedian()
{
    if(pqmin.size()==pqmax.size())
    {
        return(pqmin.top()+pqmax.top())/2.0;//point is used for the sake of typecasting
    }
    else if(pqmax.size()>pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        pqmin.top();
    }
}
signed main()
{insert(10);
cout<<findMedian()<<endl;
return 0;
}