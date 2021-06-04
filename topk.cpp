//Top K most frequent elements in the stream
//Hashing
//An array is given with the value of k,we have to output elements in decreasing frequency till we reach (k+1)th distinct elements.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,int>freq;//this hash map is made to store elements and their respective frequencies to identify the kth distinct element
    for(int i=0;i<n;i++)
    {
        int presentsize=freq.size();
        if(freq[a[i]]==0 && presentsize==k)//this loop shows that we have travelled upto kth element and element after this will be stored as the final answer and we will break from this point
        break;
        freq[a[i]]++;//this step is done to ensure increment of a particular element if we haven't recahed upto our desired element
    }
    vector<vector<int>> ans;
    map<int,int> :: iterator it;
    for(it=freq.begin();it!=freq.end();it++)
    {
        if(it->second!=0)
        ans.push__back(it->second,it->first);   
    }
    sort(ans.begin(),ans.end(),greater<pair>());
    vector<pair<int,int>>::iterator it1;
for(it1=ans.begin();it1!=ans.end();it1++)
{
    cout<<it1->second<<" "<<it1->first<<endl;
}
return 0;
}