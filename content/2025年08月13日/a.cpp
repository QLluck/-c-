#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =1e6+7;
int a[N]={0};
int b[N]={0};
int t[N]={0};
int lowbit(int x){return x&-x;}
void add(int x,int k)
{
     while(x<N)
     {
        t[x]+=k;
        x+=lowbit(x);
     }
}
int query(int x)
{
     int res= 0;
     while(x)
     {
        res+=t[x];
        x-=lowbit(x);
     }
     return res;
}
int  check(int n,int ma)
{   int ji = 0;
    if(n&1)n=n/2+1,ji=1;
    else n=n/2;
    int l =0 ;
    int r = ma+1;
    while(l+1<r)
    {
       int mid = (l+r)>>1;
       if(query(mid)<n)l=mid;
       else r =mid;
    }
    int a1=  r;
    if(ji)return r;
    else 
    {   l =0;
     r = ma+1;
    while(l+1<r)
    {
       int mid = (l+r)>>1;
       if(query(mid)<n+1)l=mid;
       else r =mid;
    }
    int a2 = r;
    return (a1+a2)>>1;
         
    }
}
 void solve()
 {
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        cin>>a[i];
        b[i]=a[i];
     }
    sort(b+1,b+n+1);
    int it = unique(b+1,b+n+1) -b-1;
    int ma =0 ;
    for(int i=1;i<=n;i++)
    {
        int x = lower_bound(b+1,b+it+1,a[i])-b;
        add(x,1);
        ma = max(x,ma);
        int ans = check(i,ma);

    }
   

 }
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}