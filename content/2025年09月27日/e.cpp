#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
const int mod = 998244353 ;
int a[N];

void solve()
{


 int n;
 cin>>n;

   for(int i=1;i<=n;i++)cin>>a[i];
int ans =0 ;
int ans1 =0 ;
   for(int i=2;i<=n;i++)
   {
    ans +=abs(-a[i]+a[i-1]);
    if(i>=3)ans1+=abs(-a[i]+a[i-1]);

   }
   ans1 = min(ans,ans1);
//    ans = min(ans1,ans);

   for(int i=2;i<=n;i++)
   {
      int sum ;
         if(n>=2&&i==n)sum = ans - abs(-a[n]+a[n-1]);
      else sum = ans - abs(a[i]-a[i-1]) - abs(-a[i+1]+a[i]) + abs(-a[i+1]+a[i-1]);
      //cout<<sum<<' '<<i<<' '<<ans<<'\n';
      ans1 =min(ans1,sum);

   }
   cout<<ans1<<'\n';
 
}
//100 i
//8
//1
//3
//12
//7
//-3
//2
//12 8 7 3 2 1 -3
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int sum = 1000000000;
    //  sum = sum*sum;
 
    // cout<<sum+1<<'\n';
    // cout<<N<<'\n';
    int t;
    cin>>t;
    while(t--)
    solve();
}