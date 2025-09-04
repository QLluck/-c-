#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =21;
const int P =1e9+7 ;
int dp[N][N];
int a[N]={0};
void init()
{
     for(int i=0;i<N; i++)
     {
         for(int j= 0 ;j<N ;j++)
         {
            if(i==0&&j==0)dp[i][j]=1;
            else if(j==0)dp[i][j]=0;
            else if(i<j)dp[i][j]=0;
            else dp[i][j] =  (dp[i-1][j-1] + dp[i-1][j]*j%P)%P;
         }
     }
     a[1]=1;
     for(int i=2; i<N; i++)a[i]= a[i-1]*i%P;
}


void solve()
{
  int n,m;
  cin>>n>>m;
  cout<<dp[n][m] *a[m] <<'\n';
    
}


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   init();
    solve();
   return 0;
}