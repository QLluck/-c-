#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+7;
int t[N]={0};
int d[N]={0};
int p[N]={0};
int dp[N]={0};

void solve()
{
   int n;
   cin>>n;
   int ma =0 ;
   for(int i =1; i<=n;i++)
   cin>>t[i]>>d[i]>>p[i],ma = max(d[i],ma);
   
   for(int i =0; i<=ma ;i++)dp[i]=0;
   for(int i =1; i<=n;i++)
   {
      for(int j =d[i];j>=t[i];j--)
      {
         int x = j-t[i];
         if(x>=0)dp[x]= max(dp[j]+p[i],dp[x]);
      }
      for(int i =0; i<=ma;i++)
      {
         cout<<dp[i]<<' ';
      }
      cout<<'\n';

   }
   int ans =0 ;
   for(int i =0; i<=ma ;i++)ans=max(ans,dp[i]);
   cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}