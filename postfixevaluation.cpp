#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfixevaluation(string s)
{
    stack<int>st;
    for(int i=s.length()-1;i>=0;i--)
    {
if(s[i]>='0' && s[i]<='9')//this condition shows that it is an operand
{
    st.push(s[i]-'0');//s[i] is a character and to make it an integer,0 is subtracted from it
}
else//this is used when expression is an operator
{
    int op2=st.top();
    st.pop();
    int op1=st.top();
    st.pop();

    switch(s[i])
    {
        case '+':
        st.push(op1+op2);
        break;

        case '-':
        st.push(op1-op2);
        break;

        case '*':
        st.push(op1*op2);
        break;

        case '/':
        st.push(op1/op2);
        break;

        case '^':
        st.push(op1^op2);
        break;
    }
}

    }
    return st.top();
}
int main()
{cout<<postfixevaluation("46+2/5*7+");
    return 0;
}