#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define se second 
#define fi first 
#define PII pair<int,int>
const int N = 1e6+7;
const int mod = 128;
int ans[N];
string a[N];
// int cnt=0;
map<string ,int >mp;
map<string,int>me;
// int shu =0 ;
int dp[N];
int f2 = 0;
int f1=0;
int cnt =0 ;
int f(int x,int p)
{
    cnt++;
    if(x<=1)return 1;
    else return ((-(p/x))*f(p%x,p) +100*p )%p;
// 
}

void solve()
{
    int n;
    cin>>n;

    int sum =0;
    for(int i=0;i<=n;i++)dp[i]=0;
    // dp[1]=1;
    // dp[0]=1;
    // int sum =0 ;
    for(int i=1;i<n;i++)
    {
        // int sum = (1+n-1)*(n-1);
       dp[i]+=dp[n%i];
       dp[i]++;
       sum+=dp[i];
        // sum+=(f(i,n)+100*n )%n;
        // sum%=n;
    }
    // cout<<sum<<'\n';
    // sum+=100*n;
    // sum%=n;
    double ans = sum/(double)(n-1);
    // cout<<cnt<<'\n';
    // cout<<ans<<'\n';
    printf("%.8lf\n",ans);
}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // init();
    cin>>t;
    while(t--)
    solve();
}