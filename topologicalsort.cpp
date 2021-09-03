#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;//here we are taking nodes and edges as input
int cnt=0;//here we have made a count variable
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;//this is for taking edges as input
    vector<vector<int>>adj(n);//yhis one is the adjacency list
    vector<int>indegree(n,0);//this one is another vector where indegree of each vertex is 0 initially
    //u-->v//this represents that an edge is getting formed from u to v
    adj[u].push_back(v);
indegree[v]++;//indegree of a node is increased if there is an incoming edge for it
}
queue<int>q;
for(int i=0;i<n;i++)
{
    if(indegree[i]==0)//we will check that if indegree of a particular vertex is 0,then we can push this into queue
    {
        q.push(i);
    }
}
while(!q.empty())//now we will move till the time q is not empty
{
    cnt++;
    int x=q.front();
    q.pop();
    cout<<x<<" ";
    //x-->v
    for(auto it:adj[x])
    {
        indegree[it--];
        if(indegree[it]==0)
        q.push(it);
    }
}
}