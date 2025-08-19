#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 
const int mod =998244353;
const int N = 1e5+7;
int a[N];
void solve()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+n+1);
   int ans =0 ;
   for(int i=1;i<=n;i++)
   {
      for(int j=i+1;j<=n;j++)
      {
           if(j!=n&&a[i]+a[j]>a[n])ans++;
           else if(j==n)ans++;
      }
   }
   cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
// 110
// 110
//1000
//1000