//CYCLE DETECTION IN UNDIRECTED GRAPH USING DSU
#include<iostream>
using namespace std;
const int N=1e5+6;//we have declared a variable N of very large value
vector<int>parent(n);//this vector is declared here to check the parent element of the vector
vector<int>sz(n);//this vector is used to perform disjoint set union using size
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    return v;
    return parent_v=find_set(parent[v]);//this is path compression
}
void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        if(sz(a)<sz(b))
            swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
int main()
{
for(int i=0;i<N;i++)
{
    make_set(i);
}
int m,n;
cin>>m>>n;
vector<vector<int>>edges;
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    edges.push_back({u,v});
}
bool cycle=false;
for(auto i: edges)
{
    int u=i[0];
    int v=i[1];
    int x=find_set(u);
    int y=find_set(v);
    if(x==y)
    {
cycle=true;
    }
    else
    {
        union_sets(u,v);
    }
}
if(cycle)
{
    cout<<"cycle is present here"<<endl;
}
else{
    cout<<"cycle is not present here"<<endl;
}
return 0;
}