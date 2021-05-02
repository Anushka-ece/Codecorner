#include<bits/stdc++.h>
using namespace std;
 int countpathmat(int n,int i,int j)//n:order of the matrix,i:iterator for traversing rows,j:iterator for traversing columns
   {    
       if(i==n-1 && j==n-1)  //base condition                           
           return 1;                         
    if(i>=n || j>=n)
     {
         return 0;
     }
     return countpathmat(n,i+1,j)+countpathmat(n,i,j+1);//once we are traversing row and other time 
                                                        //we are traversing col

   }                                 
int main()
{
    cout<<countpathmat(4,0,0)<<endl;
    return 0;
}