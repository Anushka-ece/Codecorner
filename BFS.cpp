#include "bits/stdc++.h"
using namespace std;
const int N=1e5+2;
bool vis[N];//visited array
vector<int>adj[N];//adjacency list
int main()
{
    for(int i==0;i<N;i++)
    {
        vis[i]=0;
    }
    int n,m;//we are taking no. of edges and nodes as input
    cin>>n>>m;
int x,y;//these two variables are declared for taking edges as input 
for(int i=0;i<m;i++)
{
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
//Till here,our input taking process is complete
//since we are doing BFS,it is implememted through queue
queue<int>q;
q.push(1);
vis[1]=true;//1 has been inserted into this queue and is marked as true
while(!q.empty())//we will traverse queue till the time it will not become empty
{
    int node=q.front();
    q.pop();
    cout<<node<<endl;
    //now one by one we have to visit each node and will mark visited nodes as true
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it])//this is to check if a particular node has been visited or not
        {
            vis[*it]=1;
            q.push(*it);
        }
    }
} 
    return 0;
}