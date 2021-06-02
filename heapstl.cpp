#include<iostream>
#include<string>
using namespace std;
signed main()
{
    priority_queue<int ,vector<int>>pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top();
    priority_queue<int,vector<int>,greater<int>>pqm;
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    cout<<pqm.top()<<endl;//this should give 1 as answer coz the priority fubction with 3 arguments that we have used above has converted it into minheap
    return 0;
}