#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>adj;//we have declared adjacency matrix globally
vector<bool>visited;//this vector is to check that node has been visited or not
vector<int>color;//this one isto check the coloring order on the basis of which we are going to detremine that the given graph is bipartite or not
bool bipart=false;//initially a variable is taken globally to check that whether the graph is bipartite or not
void color(int u,int curr)//u represents current node and curr represents current color
{
if(col[u]!=-1 and col[u]!=curr)
{
    bipart=false;//this will not be a bipartite as a color already been assigned to it previously
    return;
}
col[u]=curr;
if(vis[u])
return;
vis[u]=true;
for(auto i:adj[u])
{
    color(i,curr xor 1);//this will give opposite color to the previous one for the neighbouring nodes
}
}

int main()
{
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>>(n);//here initialization has taken place
    visited=vector<int>(n,false);//while initializing,we will mark everything as false because every node is unvisited initially
    color=vector<int>(n,-1);//while initializing we will mark every node as -1 for color which shows that no node has been colored yet
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])//while traversing nodes,if we found a node that is not colored then we will color it
        {
            color(i,0);//here 0 represents a color and we means that we have ,arked a particular node with that color
        }
    }
    if(bipart)
    cout<<"it is a bipartite graph";
    else
    cout<<"it is not a bipartite graph"
}