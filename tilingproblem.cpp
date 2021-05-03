#include<bits/stdc++.h>
using namespace std;
int tilingways(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return tilingways(n-1)+tilingways(n-2);//n-1 is when we have placed first tile vertically and
                                           // n-2 is when we have placed first tile horizontally
}
int main()
{int x;
cin>>x;
    cout<<tilingways(x)<<endl;
    return 0;
}