//REVERSE A STACK CODE
//In this question,we will not take a separate stack for storing the reversed elements.Rather,we will rearrange elements in the original array itself using recursion
#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int>&st,int ele)
{
    if(st.empty()){
        st.push(ele);
        return;
    }
int topele=st.top();//this step is done to take out the top element
st.pop();
insertatbottom(st,ele);

st.push(topele);
}

void reverse(stack<int>&st)//here we are calling stack by reference
{
    if(st.empty())//base condition
{
    return;//if stack is empty then there is no need of reverseing the array
}
    int ele=st.top();//through this,we are storing top element in a variable named st
    st.pop();
    reverse(st);//calling st again for the remaining stack
    insertatbottom(st,ele);
}
int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}