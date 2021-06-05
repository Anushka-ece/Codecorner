#include "bits/stdc++.h"
using namespace std;
const int N=1e5+2;
bool vis[N];//visited array
vector<int>adj[N];//adjacency list

void dfs(int node)
{
//preorder
vis[node]=1;
cout<<node<<" ";
//inorder
vector<int>::iterator it;
for(int it=adj[node].begin();it!=adj[node].end();it++)
{
if(vis[*it]);//this shows that if node has already been visited ,then we don't need to do anything
else
{
    dfs(*it);
}
}
//postorder
cout<<node<<" ";
}

int main()
{
    
    int n,m;
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);//1 is take as root node here
    return 0;
}