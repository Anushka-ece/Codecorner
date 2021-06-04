//Activity selection problem using greedy algorithm
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for (int i = 0; i < n; i++)
    {
       int start;
       int end;
       cin>>start>>end;
       v.push_back({start,end});//here we have used curly braces,this is another method to form it a vector

    }
    
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];//a[1] is the ending time of a and b[1] is the ending time of b
    });                  //this is the method of making custom comparator
    int take=1;// no. of activities taken
    int end=v[0][1];//first activity
    for(int i=1;i<n;i++)
    {
        if(v[i][0]>=end)
        {
            take++;
            end=v[i][1];
        }
    }
    cout<<take<<endl;
    return 0;
}