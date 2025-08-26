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
   for(int i=1;i<=n-2;i++)
   {
      for(int j=i+1;j<=n-1;j++)
      {
          int l = j;
          int r = n+1;
          int k1 = a[n]-a[i]-a[j];
          while(l+1<r)
          {
            int mid =(l+r)>>1;
            if(a[mid]<=k1)l=mid;
            else r= mid;
          }
          int i1 = r;
          l=j;
          r =n+1;
          while(l+1<r)
          {
            int mid=(l+r)>>1;
            if(a[mid]<a[i]+a[j])l=mid;
            else r=mid;
          }
          int i2=l;
          //int i3 = max(i1,i2);
          ans+= max(i2-i1+1,0LL);

            //cout<<i1<<' '<<i2<<' '<<i<<' '<<j<<' '<<k1<<' '<<k<<'\n';
        
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