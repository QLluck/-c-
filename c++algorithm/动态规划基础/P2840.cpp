#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
const int INF = 1e9+7;
const int P = 1e9+7;
int dp[N]={0};
int a[N]={0};
void solve()
{
    int n,w;
    cin>>n>>w;
    dp[w]=1;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i =w ;i>=0 ;i--)
     {
        
         for(int j=1;j<=n;j++)
         {
            int x = i - a[j];
            if(x>=0)dp[x] =( dp[x] + dp[i])%P;

         }
     }
    cout<<dp[0]<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}