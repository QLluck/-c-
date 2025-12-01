#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];

PII ans[N];
int ma[N];
int me[N];
PII mp[N];
int it = 0;
int n,k;
void solve()
{
    
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
 for(int i=1;i<=n;i++)me[i]=0,mp[i].fi=0,mp[i].se=0;
   for(int i=1;i<=n;i++)
   {
         int num = i-me[a[i]];
         me[a[i]]=i;
         if(num>mp[a[i]].fi)mp[a[i]].se=mp[a[i]].fi,mp[a[i]].fi=num;
         else mp[a[i]].se = max(mp[a[i]].se,num);
        //  me[a[i]]=i;   
   } 
   int mi = 1e9+7;


   for(int i=1;i<=k;i++)
   {
    if(mp[i].fi==0)continue;
    int num= n+1 - me[i];
    if(num>mp[i].fi)mp[i].se=mp[i].fi,mp[i].fi=num;
    else mp[i].se = max(mp[i].se,num);
    // cout<<a[i]<< ' '<<mp
 mi=min(mi,max( (mp[i].fi-1) /2,mp[i].se-1));
   }


   cout<<mi<<'\n';
    
           
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}
// 4 3 3  2 1
// 4 2 3 1 3