#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
int n,m;
ll arr[N]={0};
ll p[N]={0};
ll poww(ll n,ll m)
{
      ll res= 1;
      while(m)
      {
          if(m&1) res = res *n;
          m>>=1;
          n=n*n;
      }
      return res;
}
void solve()
{
  cin>>n>>m;
  for(int i=1; i<=m ;i++)
    {  cin>>arr[i];

    }
    ll sum=0;
    ll it =0 ;
    ll l=1;
    ll r =1;
    ll num =0 ;
    ll ans= 0 ;
    for(int i=1; i<=m ;i++)
    {    
        it++;
        if(i<=m-1&&arr[i]+arr[i+1] + poww(it,4) + 1 > arr[i+1]+poww(it+1,4))
        {
             continue;
        }
        else 
        {
            ans+=arr[i]+ poww(it,4) ;
           // cout<<i<<'\n';
             num=0;
             it=0;
        }
         

    }

    cout<<ans<<'\n';
  


  



}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
 

    solve();
   
}