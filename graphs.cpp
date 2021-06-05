 //FUNDAMENTALS OF GRAPH
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
vector<int>adj[N];//a list has been declared globally
const int N=1e5+2,MOD=1e9+7;
using namespace std;
signed main()
{//ADJACENCY GRAPH
    int n,m;//n is no. of nodes and m is no. of edges
    cin>>n>>m;
    //we will make a 2D vector
    vector<vector<int>>adjm(n+1,vector<int>(n+1,0)) ;// we will make an adjacency matrix
    for(int i=0;i<m;i++)
    {
int x,y;
cin>>x>>y;
adjm[x][y]=1;//we have taken this edge from x to y
adjm[y][x]=1;//similiarly,we have taken edge from y to x also as this is a directed edge
    }
    cout<<" adjacency matrix of above graph is given by : "<<endl;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout<<adjm[i][j]<<" ";
            cout<<endl;
        }
    }
    //program to find out edge between two particular nodes of a graph
    if(adjm[3][7]==1)//used to check if there exists a node between 3 and 7
    {
        cout<<"there is a edge between 3 and 7"<<endl;
    }
    else
    {
cout<<"no edge";
    }
    cout<<endl;
    //ADJACENCY LIST
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;//we eill push y in adjacency list of x and vice versa
    adj[x].push_back(y);
    adj[y].push_back(x);
}
cout<<"adjacency list of the above graph is givenby : ";
for(int i=1;i<n+1;i++)
{
    cout<<i<<"->";//this is printed to show that which array no. is there at present
    vector<int>::iterator it;
    for(it=adj.begin();it!=adj.end();it++)
    cout<<*it<<" ";
    cout<<endl;
}
    return 0;
}