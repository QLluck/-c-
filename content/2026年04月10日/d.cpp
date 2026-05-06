#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second
const int N = 1e5+7;
int a[N];
PII b[N];
int ans[N];
int dp[N];
vector<int> t[N];
void solve()
{


   int n;
   cin>>n;
   dp[0]=0;
   int sum = 0;
   for(int i=1;i<=n;i++)cin>>a[i],sum^=a[i];
   for(int i=1;i<=1e5;i++)t[i].clear();
    for(int i=1;i<=1e5;i++)
    {
        int f =0 ;
        for(int j=1;j<=n;j++)
        {
            int yi = i^a[j];
            if(yi<a[j] && dp[yi]==0 )
            {
                f=1;
                t[i].push_back(a[j]);
                break;
            }
        }
        if(f)dp[i]=1;
    }
    if(dp[sum])cout<<"Left\n";
    else cout<<"Right\n";
  
    

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}