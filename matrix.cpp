//print elemenst which are common in each row
#include<iostream>
#include<map>
using namespace  std;
#define r 4
#define c 5
void printcommonelements(int mat[r][c])
{
map<int,int>mp;
for(int j=0;j<c;j++)
{
mp[mat[0][j]]=1;
}
for(int i=1;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        if(mp[mat[i][j]]==i)
        {
            mp[mat[i][j]]=i+1;

            if(i==(r-1) && (mp[mat[i][j]]==r))
            cout<<mat[i][j]<<" ";
        }
    }
}

}
int main()
{
int mat[r][c] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printcommonelements(mat);
 
    return 0;
}