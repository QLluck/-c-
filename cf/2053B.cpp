#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
pii a[N];
int pix[N]={0};

int solve()

{

     int n;
     cin>>n;
     map<pii,int> mp;
     for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,pix[i]=0;
     for(int i=1;i<=2*n;i++)pix[i]=0;
     for(int i=1;i<=n;i++)
     {
        if(a[i].fi==a[i].se)
        {if(mp[{a[i].fi,a[i].se}]==0)pix[a[i].fi]++,mp[{a[i].fi,a[i].se}]++;
        else mp[{a[i].fi,a[i].se}]++;
        }
     }
     for(int i=1;i<=2*n;i++)pix[i]+=pix[i-1];
     for(int i=1;i<=n;i++)
     {  
        int len = a[i].se -a[i].fi +1;
        int sum = pix[a[i].se]-pix[a[i].fi-1];
        if(a[i].fi==a[i].se)
         {    if(mp[{a[i].fi,a[i].se}]>=2)cout<<0;
            else cout<<1;
         }
        else if(sum>=len)cout<<0;
        else cout<<1;
     }
     cout<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}