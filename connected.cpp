#include<iostream>
#include<vector>
using namepsace std;

 vector<bool>visited;
int n,m;
vector<vector<int>>adj(n);
vector<int>components;

int get_comp(int idx)//it is taking an index value as an argument
{
    if(vis[idx])
    return 0;
    vis[idx]=true;
    int ans=1;//initially answer is 1
    for(auto i: adj[idx])
    {
        if(!visited[i])
        {
            ans+=get_comp(i);
            visited[i]=true;
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    adj=vector<vector<int>>(n);//we have declared all thes evaraibles globally and here we are initializing them
    visited=vector<bool>(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }
    for(int i=0;i<n;i++)//traversal of all nodes
    {
        if(!visited[i])
        {
            components.push_back(get_comp(i));//if a node is not visited that means that it is a new component and hence we will add it ti the existing components list using get_comp function
            
        }
    }
    for(auto i:components)
    {
        cout<<i<<" ";//here we are printin the size of components
    }
}