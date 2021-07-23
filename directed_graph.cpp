//cycle detection in directed graph
#include<iostream>
#include<vector>
using namespace std;
bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&stack)
{
    stack[src]=true;
    if(!visited[src])
    {
        visited[src]=true;
        for(auto i:adj[src])
        {
            if(!visited[i] and iscycle(i,adj,visited,stack))
            {
                return true;

            }
            if(stack[i])
            return true;
        }
    }
    return false;
}
using namespace std;
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
    }
    bool cycle=false;
    vector<int>stack(n,0);//this is a stack to store all elemments of the tree
    vector<int>visited(n,0);//this is a visited array
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,stack))
        cycle=true;
    }
    if(cycle)
    {
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle is not present";
    }
}