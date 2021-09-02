#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first;
#define ss second;
 const int N=1e5+2,MOD=1e9+7;

signed main()
{
    int n,m;
    cin>>n>>m;
    vvi adjm(n+1,vi(n+1,0));//we have taken an adjacency list of rows and columns n+1 and initialized column with 0
    rep(i,0,m);//we are taking input of edges
    {
        int x,y; //these are the variables we are taking for edges
        cin>>x>>y;//here we have undirected edges , hence two variables
        adjm[x][y]=1;//here we are maeking edge from x to y as 1
        adjm[y][x]=1;//here we are maeking edge from y to x as 1

    }
cout<<"adjacency matrix of above graph is givenn by : "<<endl;
rep(i,1,n+1)
{
    rep(j,1,n+1)
    {
        cout<<adjm[i][j]<<" ";
        cout<<endl;
    }
}
}