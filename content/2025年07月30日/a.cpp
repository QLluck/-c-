#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int P = 1e9+7;
const int N = 1007;
int c[N][N]={0};
void init()
{
    for(int i=0;i<N;i++)
    {
        c[i][i]=1;
        c[i][0]=1;
        
    }
     for(int i=1;i<N;i++)
     {
         for(int j= 1; j<i;j++)
         {
            c[i][j] = (c[i-1][j] +c[i-1][j-1]) %P;
            c[i][i-j]=c[i][j];
         }
     }
}
int po(int a,int b)
{
     int res= 1;
     while(b)
     {
        if(b&1)res = res*a %P;
        b>>=1;
        a= a*a %P;
     }
     return res%P;
}

void solve()
{
  int n,k,m;
  init();
  cin>>n>>k>>m;
  int mi = min(n,k);
//   for(int i=1;i<=n;i++)
//   {
//      for(int j=1; j<=n;j++)cout<<c[i][j]<<' ';
//      cout<<'\n';
//   }
  int ans = c[n][k] *  po(m,k)%P;
  cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}