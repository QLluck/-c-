#include<bits/stdc++.h>
using namespace std;
const int  N = 1e4+7;
const int INF =1e9+7;

#define ll long long
int dp[N]={0};
int a[N]={0};
map<int,int>mp;
map<int,int>dmp[N];
void solve()
{



  int n,m;
  cin>>n>>m;
  for(int i =1; i<=n;i++)cin>>a[i];
  dp[m]=1;
 for(int i =1; i<=n;i++)
 {
     for(int j =1; j<=m;j++)
     {
       if(dp[j]==0)continue;
       int x = j - a[i];
       if(x>=0)
       {
           dp[x]+=dp[j];
       }
     }
 }
  cout<<dp[0]<<'\n';




}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
    solve();
}