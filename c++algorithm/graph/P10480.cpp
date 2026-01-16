#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 3e4+7;
vector<int> t[N];
bitset<N> p[N];
bitset<N> vis;
void dfs(int u)
{
    vis[u]=1;
    p[u][u]=1;
    for(auto v : t[u])
    { 
        // cout<<v<<'\n';
       if(!vis[v])dfs(v),p[u]|=p[v];
       else p[u]|=p[v];  
    }
}
void solve()
{
     int n,m;
     cin>>n>>m;
     vis.reset();
     for(int i=1;i<=m;i++)
     {
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
     }
    //  cout<<vis[1]<<'\n';
     for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
     for(int i=1;i<=n;i++)cout<<p[i].count()<<'\n';
     
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)solve();
}