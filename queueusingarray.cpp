//Implement queue using arrays
#include<iostream>
using namespace std;
#define n 20
class queue{
    int *arr;
    int front;
    int back;
    public:
    queue()//a constructor in which memory is alocatted to the array
    {
arr=new int[n];
front=-1;
back=-1;
    }
    void push(int x)
    {
        if(back==n-1)//this step is done to ensure that if any space is left or not and this condition shows that there is no space left in queue now
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;//if queue is empty then back will be incremented and element will be inserted

        if(front==-1)//in this condition,we are inserting at the first place
        {
            front++;
        }
    }
    void pop()
    {
        if(front==-1 || front>back)//this symbolises that not even a single element has been inserted into queue yet
        {
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;//this will delete element
    }
   int peek()
    {
             if(front==-1 || front>back)//this symbolises that not even a single element has been inserted into queue yet
        {
            cout<<"No elements in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
             if(front==-1 || front>back)//this symbolises that not even a single element has been inserted into queue yet
        {
            return true;
        }
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
    cout<<q.peek()<<endl;
    q.pop();
    return 0;

}