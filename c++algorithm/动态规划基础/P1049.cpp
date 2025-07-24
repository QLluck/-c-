#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7 ;
const int INF =1e9+7;
int dp[N]={0};
int a[N]={0};
void solve()
{
  int v;
  cin>>v;
  int n;
  cin>>n;
  dp[v]=1 ;
  for(int i=1;i<=n;i++)cin>>a[i];
  int ans =INF ;
  for(int i=1;i<=n;i++)
  {
       for(int j= 0 ;j<=v ;j++ )
       {
             if(j+a[i]<=v&&dp[j+a[i]])dp[j]=1,ans =min(j,ans);
       }
  }
  cout<<ans<<'\n';

 
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve() ;
 }