#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int prec(char c)//this function is to predict the preceedence of the character
{
    if(c=='^')
    return 3;
    else if(c=='%' || c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
string infixtoprefix(string s)
{
    reverse(s.begin(),s.end());
    stack<char>st;
    string res;
for(int i=0;i<s.length();i++)
{
    if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
    {
res+=s[i];
    }
    else if((s[i])=='(')
    {
        st.push(s[i]);
    }
    else if(s[i]==')')
    {
       while(!st.empty() && st.top() != '(')
       {
           res+=st.top();
           st.pop();
       } 
       if(!st.empty())//in this condition,we will get an opening bracket
       {
           st.pop();
       }
    }
    else{
        while(!st.empty() && prec(st.top()>=prec(s[i])))//this condition is for operators
        {
            res+=st.top();
            st.pop();
        }
        st.push(s[i]);
    }
}
while(!st.empty())
{
    res+=st.top();
    st.pop();
}
reverse(res.begin(),res.end());
return res;
}
int main()
{
cout<<infixtoprefix("(a-b/c)*(a/k-l)");
return 0;
}