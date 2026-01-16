#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int ma = 87;
const int mod =  998244353;

int fei[N];

void init()
{
    fei[1]=1;
    fei[2]=1;
    for(int i= 3;i<=87;i++)
    {
        fei[i]=fei[i-1]+fei[i-2];
        // cout<<fei[i]<<' '<<i<<'\n';
        if(fei[i]>1e18 || fei[i]<=0)
        { 
            break;
        }
        // cout<<fei[i]<<' '<<i<<'\n';
    }

}
int w[N];
vector<int> t[N];
map<PII,int>mp;
int f[N];
bool vis[N];
int ans =0 ;

void dfs(int u,int d)
{
    if(vis[u])return;

    if(d>=3 && f[d-1]+f[d-2]!=w[u])return;
    vis[u]=1;
    f[d]=w[u];
    if(d>=3)ans+=d-2;
    //  cout<<u<<' '<<d<<' '<<ans<<'\n';
    ans%=mod;
    for(int i=0;i<t[u].size();i++)
    {
        int v = t[u][i];
        if(d>=2 && mp[{u,v}])continue;
        mp[{u,v}]=1;
        dfs(v,d+1);
    }

    vis[u]=0;
    
}
void solve()
{
   int n,m;
   cin>>n>>m;
   mp.clear();
   ans=m;

   for(int i=1;i<=n;i++)
   {
    t[i].clear();
    vis[i]=0;
    cin>>w[i];
   }
   for(int i=1;i<=m;i++)
   {
    int u,v;
    cin>>u>>v;
    t[u].push_back(v);
   }
   for(int i=1;i<=n;i++)dfs(i,1);
   cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t=1;
    // init();
    cin>>t;
    while(t--)solve();
   
    // printb(2);
}
// 4 3 3  2 15
// 4 2 3 1 3