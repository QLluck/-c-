#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;
const ll  P = 998244353;
int arr[N]={0};
int prime[N]={0},it;
int me[N]={0};
ll po(ll a,ll b)
{  ll res =1;
     while(b)
     {
         if(b&1) res = (res* a )%P ;
         a=a*a%P;
         b>>=1;
     }
     return res %P;
}
void solve()
{  
  
  ll n;
  cin>>n;
 // cout<<2*po(2,P-2)%P<<'\n';
  if(n&1)
  {
    ll ans = 4*(po(4,(n-1)/2 ) -1+ P )%P *po(3,P-2)%P +1 %P ;
    cout<<ans<<'\n';
  }
  else 
  {
     ll ans = 2*(po(4,n/2)-1+P)%P *po(3,P-2)%P;
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