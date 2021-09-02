#include<iostream>
using namespace std;
const int N=1e5+2;
bool vis[N];//we have made a visited array
vector<int>adj[N];//here we have made an adjacency list
int main()
{
    for(int i=0;i<N;i++)
    {
        vis[i]=0;//initialized visited array with 0
    }
int n,m;
cin>>n>>m;//intake of nodes and edges
//now,we will take variables for taking input of edges
for(int i=0;i<m;i++)
{
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
//Now,since we know that,for implementing BFS,we use queue data structure
queue<int>q;
q.push(1);
vis[1]=true;//now at the first step,we will push 1 into queue ,as it is the first node of the tree,and we will mark it as true in the array
while(!q.empty())//we will keep on popping elements out of the tree,till the time it doesn't get empty
{
int node=q.front();
q.pop();
cout<<node<<endl;
vector<int>::iterator it;
for(it=adj[node].begin();it!=adj[node].end();it++)
{
if(!vis[*it])//this is the condition to check if a particular element has been visited or not
{
    vis[*it]=1;
    q.push(*it);
}
}
}
    return 0;
}