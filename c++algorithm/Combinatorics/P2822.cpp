#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =2003;
const int mod = 1e9+7;
int C[N][N];
int dp[N];
void init()
{
     for(int i=0;i<N ;i++)
     {
         for(int j=0 ;j<=i;j++)
         {   if(j==0)C[i][j]=1;
             
             else if(i==j)C[i][j]=1;
             else C[i][j] = (C[i-1][j-1]  + C[i-1][j])%mod,C[i][i-j]=C[i][j];

         }
     }
     dp[0]=1;
     dp[1]=1;
     for(int i=2; i<N;i++)dp[i]  = dp[i-1] * 4*i-2 %mod *po(i+1,mod-2)%mod;


}
int po(int a,int b)
{
     int res= 1;
     while(b)
     {
         if(b&1) res= res*a %mod ;
         b>>=1;
         a = a*a %mod ;
     }
     return res;
}

void solve()
{
  int q,k;
  cin>>q>>k;
    

}


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    init();
    solve();
   return 0;
}