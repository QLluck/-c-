#include <bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =1e4+7;
const int inf =1e9+7;

int n;
ll arr[N][2];


void solve()
{
   cin>>n ;
   for(int i=1 ;i<=n ;i++)cin>>arr[i][0]>>arr[i][1];
   ll mi = inf ;
   ll ma= 0 ; 
   for(int i =1; i<=n ;i++)
   {
      ll x = arr[i][0];
      ll k = arr[i][1];
      ll l = 0 ; 
      ll r = inf ; 
      while(l+1!=r)
      {
          ll mid = (l+r)/2;
          if(x/mid>k)l=mid;
          else r =mid ;
        //  cout<<l<<' '<<r<<' '<<x/mid<<' '<<x<<' '<<k*mid<<'\n';
      }
    if(i==1)mi=r;
    else mi=max(mi,r);
       l = 0 ; 
       r = inf ; 
      while(l+1!=r)
      {
          ll mid = (l+r)/2;
          if(x/mid>=k)l=mid;
          else r =mid ;
      }
    if(i==1)ma=l;
    else ma = min(l,ma);



   }
   cout<<mi<<' '<<ma<<'\n' ;
 
}
int main()
{  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   solve();
  // 请在此输入您的代码
  return 0;
}