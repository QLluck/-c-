#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
const int P =1e9+7;
ll po(ll x,ll n)
{
      ll res= 1;
      while(n)
      {
         if(n&1)res = res*x%P;
         x = x*x %P;
         n>>=1;
      }
      return res%P;
}
ll po2(ll x,ll n)
{
    ll res = 0 ;
    ll sum = x ;
    while(n)
    {
        res= (res+ n%x *sum  )%P;
        sum=sum*x%P ;
        n/=x ;
    }
    return res%P;
}
void solve()
{
     ll l,r,k;
     cin>>l>>r>>k;
     ll ans =0 ;
    
  
         if(k==0||k==1)
         {
            ans = (po(10,r)%P-po(10,l)%P +P )%P;
         }
         else if(k==2)  ans = (po(5,r)%P-po(5,l)%P +P )%P;
         else if(k==3)  ans = (po(4,r)%P-po(4,l)%P +P )%P;
         else if(k==4)  ans = (po(3,r)%P-po(3,l)%P +P )%P;
         else if(5<=k&&k<=9) ans = (po(2,r)%P-po(2,l)%P +P )%P;
         cout<<ans<<'\n';
        
     
      
}
signed main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}