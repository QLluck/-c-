#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second
const int N = 1e4+7;
int a[N];
int d[N];
int me[N];
int df[N];
stack<int>sta;
int instack[N];
int ans[N];
int dfn[N],low[N];
int cnt=0,cntb=0;
vector<int> e[N];
vector<int> ef[N];
vector<int>belog[N];
map<int,int>mp;
bitset<N> p[N];
bitset<N> pf[N];

// int find(int x)
// {
//     if(x==me[x])return me[x];
//     else return me[x] = find(me[x]);
// }
void tarjan(int u)
{
     instack[u]=1;
     sta.push(u);
     ++cnt;
     dfn[u]=low[u]=cnt;
     for(int i=0;i<e[u].size();i++)
     {
        int v = e[u][i];

           if(!dfn[v])
           {
            tarjan(v);
            low[u]=min(low[u],low[v]);
           }
           else if(instack[v])
           {
                low[u]=min(dfn[v],low[u]);
           }
     }
    if(low[u]==dfn[u])
    {
     int node ;
     cntb++;
     do
     {
        node = sta.top();
        sta.pop();
        belog[cntb].push_back(node);
        instack[node]=0;
     } while (node!=u);
    }
     
     
}

bitset<N> bfs(int u,vector<int> e[],bitset<N> p[])
{
    p[u][u]=1;
    for( auto v:e[u])
    {
          if(p[v].count()) p[u]|=p[v];
          else p[u]|=bfs(v,e,p);
    }
    return p[u];
    
}
void solve()
{
 
cnt=0,cntb=0;
     int n,m;
     cin>>n>>m;
     mp.clear();
     for(int i=1;i<=n;i++)dfn[i]=0,low[i]=0,instack[i]=0,e[i].clear(),ef[i].clear(),d[i]=1,df[i]=1,ans[i]=0,me[i]=1,p[i].reset(),pf[i].reset();
      int zi =0 ;
     for(int i=1;i<=m;i++)
     {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        ef[v].push_back(u);
        if(u==v)zi=1;

     }
     if(zi)
     {
        for(int i=1;i<=n;i++)cout<<0;
        cout<<'\n';
        return;
     }
     
     for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
         if(n!=cntb)
     {
        for(int i=1;i<=n;i++)cout<<0;
        cout<<'\n';
        return;
     }
       for(int i=1;i<=n;i++)if(!p[i].count())bfs(i,e,p);
      for(int i=1;i<=n;i++)if(!pf[i].count())bfs(i,ef,pf);
        for(int i=1;i<=n;i++)
        {    
            d[i]=p[i].count();
            df[i]=pf[i].count();
            int sum = d[i]+df[i]-1;
            int num = n -sum;
            if(df[i]+num>=d[i] && d[i]+num>=df[i])
            {
                ans[i]=1;
            }
            
        }

    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<'\n';
     
    
 
   

}


signed main()
{  

    ios::sync_with_stdio(0),cout.tie(0),cout.tie(0);
    int t;
    t =1;
    
    cin>>t;
    while(t--)
    solve();
}
// 1
// 2019 5 12 Monday
// 2019 5 12