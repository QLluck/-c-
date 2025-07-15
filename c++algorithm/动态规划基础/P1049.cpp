#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7 ;
int dp[N]={0};
int arr[N]={0};
void solve()
{
  int n,m;
  cin>>m>>n;
  for(int i=1; i<=n;i++)cin>>arr[i];
 dp[m]=1;
  for(int i =1; i<=n;i++)
  {
     for(int j =arr[i] ;j<=m ;j++)
     {
        if(dp[j]==0)continue;
        int x = m-arr[j];
        if(x>=0)dp[x]=1;
     }
     for(int j =1;i<=m;i++)
     {
         cout<<dp[i]<<' ';
     }
cout<<'\n';
  }
  int ans =0 ;
  while(dp[ans]==0&&ans<m)ans++;
  cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve() ;
 }