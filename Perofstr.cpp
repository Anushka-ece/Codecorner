#include<bits/stdc++.h>
using namespace std;
void permutation(string s,string ans)//ans is an empty string in which every permutation is stored
{
    if(s.length()==0)   //base condition
    {
        cout<<ans<<endl;
        return;
    }
    //We will fix  a certain character and perform the permutations 
    //of the remaining string
    for(int i=0;i<s.length();i++)//this loop is for fixing characters one by one
    {
        char ch=s[i]; //Put fixed character in ch
                      //Take rest of the string to the left and 
                      //to the right of the fixed character ch
        string ros=s.substr(0,i)+s.substr(i+1);//in substr(a,b)-a denotes starting 
                                               //point and b denotes length of the substring taken
        permutation(ros,ans+ch);
    }

}
int main()
{
   permutation("AB","");
   return 0;
}