#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first
#define se second
const int P = 1e9+7;
const int N = 1e6+7;
const int INF = 1e18+7;
int a[N]={0};
int p[N]={0};
int b[N]={0},it;
pii w[N];
void solve()
{ 
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
     cin>>a[i];
     b[++it]=a[i];
   }
   for(int i=1;i<=m;i++)
   {
      cin>>w[i].fi >>w[i].se;
      b[++it] = w[i].fi;
   }
   sort(b+1,b+it+1);
   it = unique(b+1,b+it+1)-b-1;
   for(int i=1;i<=m;i++)
   {
     int g = lower_bound(b+1,b+it+1,w[i].fi) - b;
     p[g]+=w[i].se;
   }
   for(int i=1;i<=it ;i++)p[i]=p[i-1]+p[i];
   for(int i=1;i<=n;i++)
   {
     int g = lower_bound(b+1,b+it+1,a[i])-b;
     cout<<p[g]<<' ';
   }
   cout<<'\n';



}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    //int t;
    
    // cin>>t;
    // while(t--)
    solve();
}