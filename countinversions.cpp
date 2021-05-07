#include<iostream>
using namespace std;

long long merge(int arr[],int l,int mid,int r)
{
    long long inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=1;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {arr[k]=a[i];
        k++;i++;}
        else
   { arr[k]=b[j];
    inv+=n1-i;//since if first lement of a[i] is greater than first element of b[j] 
    //then all the further elements of a[i] will also be greater
    k++;j++;
    }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2)
    {
        arr[k]=a[j];
        k++;j++;
    }
    return inv;
}
long long mergesort(int arr[],int l,int r)//since there can be many inversions 
                                          //hence we have stored it in long long 
                                          //data type
{
    long long inv=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        inv+=mergesort(arr,1,mid);//it will give inversions on left part
        inv+=mergesort(arr,mid+1,r);//it will give inversions on right part
        inv+=merge(arr,l,mid,r);//it will give inversions produced after
                                // merging these two arrays
    }
    }
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mergesort(arr,0,n-1);
    return 0;
}