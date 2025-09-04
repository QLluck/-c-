#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
int a[N];
int pix[N]={0};
void solve()

{

     int n,x,y;
     cin>>n>>x>>y;
     int sum =0 ;
     for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
     sort(a+1,a+n+1);
     a[n+1]=0;
     int ans =0;
     for(int i=1;i<=n-1;i++)
     {
        int l =0 ;
        int r = n+1;
    int x1 = sum-a[i]-x;
          while(l+1<r)
    {
        int mid =(l+r)>>1;
        if(a[mid]<=x1)l=mid;
        else r =mid;
        //cout<<a[mid]<<' '<<l<<' '<<r<<'\n';
    }
    int jr = l;
    x1 = sum-a[i]-y;
    l=0;
    r=n+1;
              while(l+1<r)
    {
        int mid =(l+r)>>1;
        if(a[mid]<x1)l=mid;
        else r =mid;
       // cout<<a[mid]<<' '<<l<<' '<<r<<'\n';
    }
    int jl =r ;
     jl = max(jl,i+1);
    jr =min(jr,n);
   // cout<<jl<<' '<<jr<<'\n';
    if(sum-a[i]-x<a[jl])continue;
    if(sum-a[i]-y>a[jr])continue;
    ans = ans +max(jr-jl+1,0LL);  

     }
    // sum -i-j<=y  sum-i-y<= j ;
              //  j <=sum-i-x;
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}