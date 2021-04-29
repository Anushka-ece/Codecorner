//To find minimum and maximum element in an array
#include<iostream>
using namespace std;
int main()
{
    int size=5;
    
    int numbers[size]={1,2,3,-40,40};
    
    int maximum=numbers[0];
    int minimum=numbers[0];
    for(int i=0;i<size;i++)
{
    if(minimum>numbers[i])
    minimum=numbers[i];
    if(maximum<numbers[i])
    maximum=numbers[i];
}
cout<<"MAX:"<<maximum<<endl;
cout<<"MIN:"<<minimum<<endl;
return 0;

}