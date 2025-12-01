#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e8+7;
int prime[N],it=0;
bool me[N]={0};
int a[N];

void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    int sum = 0 ;
    int ans =0 ;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=32 ;i>=0 ;i--)
    {    
        ans += min(sum*x,y);
        if(sum*x<=y)
        sum*=2;
          for(int j=1;j<=n;j++)if( (a[j]>>i)&1 )sum++,ans+=x;
        //   cout<<sum<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    pri();
    cout<<it<<'\n';
    // solve();
    // te();
}
