#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e4 + 7;
ll d1[N]={0};
ll d2[N]={0};

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  int r = 0 ;
  for(int i= 1; i<=n;i++)
  {
     int a ;
     cin>>a ;
     if(a==0)
     {
         r= 0 ;
         continue;
     }
     else 
     {
         r++;
         d1[1]++;
         d1[r+1]--;
     }

  }
  r=0;
  for(int i= 1; i<=m;i++)
  {
     int a ;
     cin>>a ;
     if(a==0)
     {
         r= 0 ;
         continue;
     }
     else 
     {
         r++;
         d2[1]++;
         d2[r+1]--;
     }

  }
  for(int i = 1; i<=n ;i++) d1[i]=d1[i-1]+d1[i];
  for(int i = 1; i<=m ;i++) d2[i]=d2[i-1]+d2[i];
    // for(int i = 1; i<=n ;i++)cout<<d1[i]<<' ';
    // cout<<'\n';
    // for(int i = 1; i<=m ;i++) cout<<d2[i]<<' ';
    // cout<<'\n';
  ll ans =0 ;
   if(n>=m)
   {
     for(int i =1; i<= m ;i++)
     {
         if(k%i==0) 
          {  
            if(m>=i&&(n>=k/i))ans+= d2[i]*d1[k/i];
          }
     }
   }
   else 
   {
      for(int i =1; i<=n ;i++) if(k%i==0&&n>=i&&(k/i)<=m) ans+= d1[i]*d2[k/i];
   }
   cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

        solve();
}