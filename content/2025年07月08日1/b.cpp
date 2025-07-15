#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =35 ;
int me[N]={0};
void f(ll x)
{
    for(int i =33 ;i>=0 ;i-- )
    {
         if(x&1)me[i]++;
         x>>=1;
    }
}

void solve()
{
 // for(int i =0 ;i<=33 ;i++)me[i]=0;
  ll n,x,y;
  cin>>n>>x>>y;
  for(int i = 1; i<=n;i++)
  {
    ll a ;
    cin>>a;
    f(a);
  }
  ll sum =0 ;
  ll sum1 =0 ;
  ll ans =0 ;
  int it =0 ; 
  while(me[it]==0&&it<33)it++;

  sum = me[it];
  sum1 = me[it];
  ans = me[it]*x;
  for(int i =it+1; i<=33 ;i++)
  { sum1 = sum ;
    sum = sum*2 ;
    if(sum1*x<=y)
    {
        ans+=sum1*x;
    }
    else 
    {
       ans+=y;
    }

    sum += me[i];
    
    ans+=me[i]*x;
  }
cout<<ans<<'\n';
  
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    // ll x= 1;
    // ll a = x<<31;; i
    // cout<<a<<'\n';
    solve();
}