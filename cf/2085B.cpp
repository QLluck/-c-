#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 2e5+7;
int a[N]={0};
int pl[N]={0};
int pr[N]={0};
pii ans[N];
void solve()
{
     int n;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i],pl[i]=0,pr[i]=0;
   for(int i=1;i<=n;i++)
   {if(a[i]==0)
      pl[i]=pl[i-1]+1;
      else pl[i]=pl[i-1];
   }
   pr[n+1]=0;
   for(int i=n;i>=1;i--)
   {
      if(a[i]==0)
      pr[i]=pl[i+1]+1;
      else pr[i]=pr[i+1];
   }
   int it =0 ;
   for(int i=1;i<=n;i++)
   {
      if(a[i]==0)continue;
      if(pl[i]&&pr[i])
      { 
          if(i==2)
         {
            cout<<3<<'\n';
            cout<<1<<' '<<2<<'\n';
            cout<<2<<' '<<n-1<<'\n';
            cout<<1<<' '<<2<<'\n';
            return;
         }
         else if(i==n-1)
         {
            cout<<3<<'\n';
            cout<<n-1<<' '<<n<<'\n';
            cout<<1<<' '<<n-2<<'\n';
            cout<<1<<' '<<2<<'\n';
            return;
         }
         else 
         {
            cout<<3<<'\n';
            cout<<1<<' '<<i-1<<'\n';
            cout<<3<<' '<<n-i+2<<'\n';
            cout<<1<<' '<<3<<'\n';
            return;
         }
      }
      else if(pl[i])
      {
         if(i==n)
         {
            cout<<2<<'\n';
            cout<<1<<' '<<i-1<<'\n';
            cout<<1<<' '<<2<<'\n';
            return;
         }
         else 
         {
            cout<<2<<'\n';
          cout<<1<<' '<<i<<'\n';
          cout<<1<<' '<<n-i+1<<'\n';

         return;
         }

      }
      else if(pr[i])
      {
         if(i==1)
         {
            cout<<2<<'\n';
            cout<<2<<' '<<n<<'\n';
            cout<<1<<' '<<2<<'\n';
            return;
         }
         else 
         {
            cout<<2<<'\n';
          cout<<i<<' '<<n<<'\n';
          cout<<1<<' '<<i<<'\n';

         return;
         }
      }
      else 
      {
         cout<<1<<'\n';
         cout<<1<<' '<<n<<'\n';
         return;
      }
   }
     cout<<3<<'\n';
     cout<<1<<' '<<2<<'\n';
     cout<<2<<' '<<n-1<<'\n';
     cout<<1<<' '<<2<<'\n';

     

   //cout<<res<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
       { solve();
       }
}