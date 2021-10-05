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
    int n,m;//n is number of nodes and m is number of edges
    cin>>n>>m;
    vectorvector<int>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;//here we are taking weights also in input
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());//edges are sorted according to the weights
    int cost=0;
    for(auto i:edges)
    {
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)//this means that they lie in the same set and hence,it will form a cycle and therefore,this will not be a MST and hence ignored
        {
            continue;
        }
        else
        {
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_sets(u,v);
        }
    }
    cout<<cost;
}
