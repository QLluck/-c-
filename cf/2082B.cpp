#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 507;

ll mi(ll x,ll n,ll m)
{
    while(m)
  {
     
      if(x&1)x=(x>>1)+1;
      else x>>=1;
      m--;
  }
  while(n)
  {
     x>>=1;
    n--;
  }
  
  return x ;

}
ll ma(ll x,ll n, ll m)
{
   
    while(n)
  {
    x>>=1;
    n--;
  }
  while(m)
  {
    if(x&1)x=(x>>1)+1;
    else x>>=1;
    m--;
  }
  
  return x ;
}
int f(int x )
{   int res= 0; 
      while(x)
      {
        res++;
        x>>=1;
      }
      return res;
}
void solve()
{
  ll x,n,m;
  cin>>x>>n>>m;
  if(x==0)
  {
    cout<<0<<' '<<0<<'\n';
    return;
  }
  int len =f(x);
  if(n>=len)
  {
    cout<<0<<' '<<0<<'\n';
    return;
  }
  if(n+m>len)
  {
    if(n)cout<<0<<' '<<1<<'\n';
    else 
    cout<<1<<' '<<1<<'\n';
    return;
  }
  
  cout<<mi(x,n,m)<<' '<<ma(x,n,m)<<'\n';

  
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}