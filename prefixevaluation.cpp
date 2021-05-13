#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefixevaluation(string s){
    stack<int>st;//stack formation for storing the expression
    for(int i=s.length()-1;i>=0;i--)
    {
if(s[i]>='0' && s[i]<='9')//this condition shows that it is an operand
{
    st.push(s[i]-'0');
}
else//this is used when expression is an operator
{
    int op1=st.top();
    st.pop();
    int op2=st.top();
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
{cout<<prefixevaluation("-+7*45+20");
    return 0;
}