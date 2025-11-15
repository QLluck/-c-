#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
#define endl '\n'
const int N = 2007;
int a[N];
pii dp[N][N];
void solve()
{
    int n;
    cin>>n;
    int it =0 ;
    int ans= 0;
    for(int i=1;i<=n;i++)
    { cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        cout<<a[i]-a[i-1]<<' ';
    }
cout<<endl;

}
void te()
{
     int n,x,y;
     n=10;
     cin>>x>>y;
     for(int i=1;i<=n;i++)cout<<x*i+y<<' ';
     cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // solve();
    te();
} 
// 
