#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define n 100// we have assumed value of 100 for n
class stack
{
    int* arr;//meking this one dynamically
    int top;//used to check that which one is topelement of the array
    public:
    stack()//constructor
    {
        arr=new int[n];//this is done to allocate new memory to array
        top=-1;
    }
    void push(int x)
    {
        if(top==n-1)//this condition is used to check that whether top has reached to the last index or not
        {
            cout <<"Stack Overflow"<< endl;
            return;
        }
        top++;//top is incremented otherwise
        arr[top]=x;//inserting elemets in stack;
    }
    void pop()//this is for popping elements from the top of the stack
    {
if(top==-1)
{
    cout <<"No element to pop"<< endl;
    return;
}
top--;
    }
    int Top()
    {if(top==-1)
    {
        cout <<"No element in stack"<<endl;
        return -1;
    }
        return arr[top];
    }
    bool empty()
    {
        return top==-1;//if array is empty then -1 is returned
    }
};
int main()
{
stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
cout <<s.Top()<< endl;
s.pop();
cout <<s.Top()<< endl;
s.pop();
s.pop();
s.pop();
cout <<s.empty()<< endl;
return 0;
}