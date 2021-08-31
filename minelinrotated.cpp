//find minimum element in a rotated subarray
#include<iostream>
using namespace std;
int main()
{
    int arr=[4,5,6,7,0,1,2];
    int minel=arr[0];
    for(int i=0;i<7;i++)
    {
if(minel>=arr[i])
minel=arr[i];
    }
    cout<<minel;
    return 0;
}