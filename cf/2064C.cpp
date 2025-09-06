#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
int a[N];
pii b[N];

void solve()
{
  int n;
cin>>n;

for(int i =1;i<=n;i++)
{
    cin>>a[i];
}
b[n+1].fi=0;
b[n+1].se=0;
b[0].se=0;
b[0].fi=0;
for(int i=1;i<=n;i++)
{
    if(a[i]>=0)b[i].fi=b[i-1].fi+a[i];
    else b[i].fi=b[i-1].fi;
}
for(int i = n; i>=1;i--)
{
    if(a[i]<0)b[i].se =b[i+1].se+a[i];
    else b[i].se=b[i+1].se;
}
int ans= 0 ;
// for(int i=1;i<=n;i++)
// {
//     cout<<b[i].fi<<' ';
// }
// cout<<'\n';
// for(int i=1;i<=n;i++)cout<<b[i].se<<' ';
// cout<<'\n';
for(int i=1;i<=n;i++)
{
    ans = max(ans,abs(a[i])+b[i-1].fi+abs(b[i+1].se ));
}
cout<<ans<<'\n';
    
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}