#include<algorithm>
#include<string>
using namespace std;
void heapify(vi &a,int n,int i)//i is starting point
{
int maxidx=i;
int l=2*i+1;
int r=2*i+2;
if(l<n && a[l]>a[maxidx])
maxidx=l;
if(r,N && a[r]>a[maxidx])
maxidx=r;
if(maxidx!=i)
{
    swap(a[i],a[maxidx]);
    heapify(a,n,maxidx);
}
}

void heapsort(v1 &a)//we have taken value by reference as whole variable will not be copied and only one element will be considered
{
int n=a.size();
for(int i=n/2-1;i>=0;i--)//we have started from first non-leaf element here
{
    heapify(a,n,i);
}
for(int i=n-1;i>0;i--)
{
    swap(a[0],a[i]);
    heapify(a,i,0);
}
}
signed main()
{
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    cin>>a[i];
    heapsort(a);
    rep(i,0,n)//rep is a macro that we have used here to avoid the usage of for and to avoid wasting extra time
    {
        cout<<a[i]<<" ";
    }
    return 0;
}