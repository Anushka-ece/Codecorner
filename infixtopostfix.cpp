#include<iostream>
#include<stack>
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
string infixtopostfix(string s)
{
    stack<char>st;
    string res;//this variable is used to store the answer
    for(int i=0;i<s.length();i++)
    {
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') )
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
res+=st.top();
st.pop();  
            }if(!st.empty())
            {
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }


    }while(!st.empty())
    {
        res+=st.top();
        st.pop();//this step is done at end to check that if nothing is left in stack at the end
    }
    return res;
}
int main()
{
cout<<infixtopostfix("(a-b/c)*(a/k-l)")<<endl;
return 0;
}