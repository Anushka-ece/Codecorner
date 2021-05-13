//REVERSE A SENTENCE USING STACK
#include<iostream>
#include<stack>
using namespace std;

void reversesentence(string s)//to reverse the entire string ,our first step would be to separate all the words firstly.Whenever,we will found a space,other word will get started.Here,we are using LIFO approach
{
stack<string> st;
for(int i=0;i<s.length();i++)
{
    string word="";//In this variable,we will store each word one by one
    while(s[i]!=' ' && i<s.length())//this condition is used to detect space and to change word in the variable named word
    {
word+=s[i];
i++;
    }
    st.push(word);
}

while(!st.empty())//this condition is used to check that it will operate till the stack is not empty
{
    cout<<st.top()<<" ";//used to remove the element at the top or the last inserted element first in order to reverse the sentence
    st.pop();
}cout<<endl;
}

int main()
{
string s="Hey,how are you doing?";
reversesentence(s);
return 0;
}