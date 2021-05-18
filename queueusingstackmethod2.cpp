//using function call stack,implement queue
#include<iostream>
using namespace std;
class queue{
    stack<int> s1;
  
    public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if(s1.empty() )
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
       int x=s1.top();
       s1.pop();
       if(s1.empty())//this depicts the condition that stack has only one single element
       {
           return x;
       }
       int item=pop();
       s1.push(x);
       return item;
    }
    bool empty()
    {
        if(s1.empty())
        return true;
        else
        return false;
    }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
     q.push(5);
     cout<<q.pop()<<endl;
     cout<<q.pop()<<endl;
     cout<<q.pop()<<endl;
     cout<<q.pop()<<endl;
     return 0;
}