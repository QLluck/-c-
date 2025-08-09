#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =5003;
const ll P =998244353;
 int arr[N]={0};
ll dp[5007][5007]={0};
ll a[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    ll ans= a[m]*dp[n][m]%P;
    cout<<ans<<'\n';
}
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0 ;j<N ;j++)
        {
            if(i==0&&j==0)dp[i][j]=1;
            else if(j==0)dp[i][j]=0;
            else if(i<j)dp[i][j]=0;
            else if(i==j)dp[i][j]=1;
            else dp[i][j]  =  (dp[i-1][j-1] + j*dp[i-1][j] %P)%P ;
        }  
    }
    a[1]=1;
    for(int i=2;i<N;i++)a[i] = a[i-1]*i%P;
}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    init();
    solve();
   return 0;
}