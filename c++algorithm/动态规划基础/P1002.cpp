#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define fi first
#define se second 
#define pii pair<int,int>
const int N =1e3+7 ;
const int INF =1e9+7;
int dp[N][N]={0};
int rx[8]={-1 , -1, -2,-2 ,1,1 ,2 , 2 };
int ry[8]={2 , -2 ,1 ,-1, 2 ,-2 ,1,-1 };
int n,m;
void bfs(int sx,int sy)
{
    queue<pii> que;
    que.push({sx,sy});
    dp[sx][sy]=-1;
    while(que.size())
    {
        pii u = que.front();
        que.pop();
        for(int i=0;i<8;i++)
        {
            int x1 = u.fi +rx[i];
            int y1 = u.se +ry[i];
            if(x1<0||x1>n||y1<0||y1>m)continue;

            dp[x1][y1]=-1;
        }
    }
}
int a[N]={0};
void solve()
{
 
    int x,y;
cin>>n>>m>>x>>y;

// for(int i =0 ;i<=m;i++)dp[0][i]=1;
// for(int i =0 ;i<=n;i++)dp[i][0]=1;
bfs(x,y);
dp[0][0]=1;
 for(int i =0 ;i<=n;i++)
 {
     for(int j =0; j<=m ;j++)
     {    if(i==0&&j==0)continue;
         if(dp[i][j]==-1)dp[i][j]=0;
         else 
         {
             dp[i][j]=  ((i-1<0)?0:dp[i-1][j]) + ((j-1<0)?0:dp[i][j-1]) ;
            // cout<< ((i-1<0)?0:dp[i-1][j])<< ' '<<((j-1<0)?0:dp[i][j-1])<<i<<' '<<j<<'\n';
         }
     }
 }
//  for(int i=0;i<=n;i++)
//  {
//    for(int j=0; j<=m;j++)cout<<dp[i][j]<<' ';
//    cout<<'\n';
//  }
 cout<<dp[n][m]<<'\n';
 
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve() ;
 }