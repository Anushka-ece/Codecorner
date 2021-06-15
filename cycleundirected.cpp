//detect cycle in an undirected graph

#include<bits/stdc++.h>
using namespace std;

bool iscycle(int src,vector<vector<int>>adj,vector<bool>&visited,int parent)
{
visited[src]=true;
for(auto i:adj[src])
{
    if(i!=parent)//this is to check that whether the node we are considering is not parent
    {
        if(visited[i])
        return true;
        if(!visited[i] and iscycle(i,adj,visited,src))
        return true;
    }
}
return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;
    vector<bool>visited(n,false);//initially we have marked all the vertices as false in the visited vector array
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,-1))//this -1 will show that whether the node is parent node or not
        {
            cycle=true;
        }
    }
    if(cycle)
    cout<<"Cycle is present";
    else
    {
        cout<<"cycle is not present";
    }
}