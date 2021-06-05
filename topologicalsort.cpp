//An ordering of the sequence of ebents is called as topological sort
#include"bits/stdc++.h"
using namespace std;
int32_t int main()
{
   int n,m;
   cin>>n>>m;
   int cnt=0;
   vector<vector<int>>adj(n);//we will make an adjacency list here
   vector<int<indeg(n,0);
   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       adj[x].push_back(y);
       indeg[y]++;//here we have to increase number of indegree as well 
      
   }
   queue<int>pq;
   for(int i=0;i<n;i++)
   {
       if(indeg[i]==0)//this shows that if operation is successful ,then in that case element will be pushed
       {
           pq.push(i);
       }
   }
   while(!pq.empty())
   {
cnt++;
int x=pq.front();
pq.pop();
cout<<x<<" ";
for(auto it:adj[x])
{
    indeg[it]--;
    if(indeg[it]==0)
    pq.push(it);
}
   }
    return 0;
}
