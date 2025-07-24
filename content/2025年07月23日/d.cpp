#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const double pi = 3.1415926535;
const int N = 1e5+7;
const int P = 1e9+7;
pair<int,int> dp[5003][5003];
int gcd(int a,int b)
{
     if(a>b)swap(a,b);
     while(a)
     {
        int temp = b%a;
        b= a;
        a =temp;
     }
     return b;
}
void solve()
{
     
      int n,m;
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      for(int j=1; j<=n;j++)
      dp[i][j].fi=0,dp[i][j].se=i;
      
      for(int i= 1; i<=n;i++)
      { dp[i][1].fi= 1  ;
       
          for(int j =1; j <i ;j++)
          {
             

                for(int g = m-1; g>=1; g--)
                {
                    if(gcd(i,dp[j][g].se)!=1)
                 {   dp[i][g+1].fi = (dp[i][g+1].fi+ dp[j][g].fi)%P;
                    dp[i][g+1].se = gcd(i,dp[j][g].se);
                 }
                }

              
          }
      }
      int ans =0;
      for(int i=1 ;i<=n;i++)
      {
         for(int j=1 ;j<=m;j++)
         {
             cout<<dp[i][j].fi<<' ';
         }
         cout<<'\n';
      }
      for(int i=m; i<=n;i++)
      {
         ans = (ans+dp[i][m].fi)%P;
      }
      cout<<ans<<'\n';
   
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}