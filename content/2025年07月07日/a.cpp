#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x,ll a,ll b,ll n )
{
     return -b*x*x + (a+b*n-1)*x + n ;
}
void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    if(b==0)
    {  ll ans =0;
        ans = max(f(0,a,b,n),ans);
        ans = max(f(n,a,b,n),ans);
        cout<<ans<<'\n';
    }
    else 
    {
         double x = (double)(a+b*n-1)/2/b;
         ll x1 = ceil(x);
         ll x2 = floor(x);
         ll ans =0 ;
          if(0<=x1&&x1<=n)ans = max(f(x1,a,b,n),ans);
          if(0<=x2&&x2<=n)ans = max(f(x2,a,b,n),ans);
          ans = max(f(0,a,b,n),ans);
          ans = max(f(n,a,b,n),ans);


         cout<<ans<<'\n';

    }
   
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}