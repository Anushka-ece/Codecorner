//LECTURE 170 CODING PROBLEM AD C++ COURSE
#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<char>>&A,int x,int y)//here we need to call by reference
{
    A[x][y]='*';
    int dx[]={0,0,-1,1};
    int dy={1,-1,0,0};
    for(int i=0;i<4;i++)
    {
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0 and cx>A.size() and cy>=0 and cy<A[0].size() and A[cx][cy]=='O')
        {
            change(A,cx,cy);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>A(n,vector<char>m);//we have made a 2D grid here which has characters as it's inputs
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 or i==n-1 or j==0 or j==m-1)
            {
                change(A,i,j);//convert into *
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O')
            {
                A[i][j]='X';
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='*')
            {
                A[i][j]='O';
            }
        }
    }
}