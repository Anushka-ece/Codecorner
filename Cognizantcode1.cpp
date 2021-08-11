//Ques: Given a number N, Find number of primes which are less than N and don't have a digit 0 in them
//EXAMPLE: Input- 4,Output- 2,3

//Solution Approach: To solve this problem in an efficient approach,we can use sieve method(Sieve of Eratosthenes).In this method,
//we basically mark all prime numbers as 1 and non prime numbers as 0
//After checking a prime number,we will check that whether this number contains zero or not.There will be 
//a separate function for that purpose

#include<iostream>
using namespace std;
int helper(int n)
{
while(n>0)
{
    int temp=n%10;
    if(temp==0)
    return 0;
    n/=10;
}
return 1;
}

void make_sieve(int arr[],int n)//this function is for making the sieve for storing the array elements
{
arr[1]=0;
arr[2]=1;
for(int i=3;i<=n;i++)
{
    if(arr[i]==1)//this condition shows that if a particular element is prime
    {
        //now all the multiples of this prime number will be non prime e.x. multiples of prime number 3 like 6,9,12,18 are non prime
        for(int j=i*i;j<=n;j+=2*i)//we are tracking only odd elements here ex. 3 9 15 and not 6 and 18
        {
            arr[j]=0;// wehave marked all the odd factors of a prime number as 0
        }
    }
}
return ;
}

int main()
{
int n;
cin>>n;
//we are building a sieve
int arr[n-1]={0};//Initially,we have initialized all numbers with 0
for(int i=3;i<n;i+=2)//since we know that all the even digits other than 2 are not prime,hence we can skip 
//all the even numbers,since all odd numbers are not prime,but they can be prime ,hence we will track only 
//odd elements one by one
{
arr[i]=1;//Initially,we have marked all the odd numbers as 1
}
make_sieve(arr,n);// after marking all the odd elements as one,i.e as prime,we will call the sieve function and
///will check out that which number is actually a prime number
int count=0;
for(int i=0;i<=n;i++)
{
if(arr[i]==1)//this one is to check that whether this value of array is a prime number or not
{
    //now we have to check that whether this prime number contains 0 or not
count+=helper(i);
}
}
cout<<count;
return 0;
}
