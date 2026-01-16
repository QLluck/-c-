#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
struct node
{
    int id, l, x, r, y, num;
};
node o[N];
int ans[N],it;
vector<int> en;
vector<int> t[N];
vector<int> e[N];

int dfn[N],low[N],cnt,sccn,insta[N],bel[N],din[N];
stack<int> sta;
vector<int > scc[N];
deque<int> ans2;
map<int,int>me;
int sum[N];
void tarjan(int u)
{
    dfn[u]=low[u]=++cnt;
    insta[u]=1;
    sta.push(u);
    for(int i =0 ;i<t[u].size();i++)
    {
        int v = t[u][i];
        if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
        else if(insta[v])low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u])
    {
        sccn++;
        int v ;
        do
        { 
            v=sta.top();
            sta.pop();
            insta[v]=0;
            bel[v]=sccn;
            scc[sccn].push_back(v);

        } while (v!=u);
        
        
    }

}
void dfs(int u)
{
    me[u]=1;
    // cout<<"YES"<<'\n';
    for(int i=0 ;i<t[u].size();i++)
    {
        int v= t[u][i];
        ans2.push_back( e[u][i] );
        if(!me[v])dfs(v);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    it =0,cnt=0,sccn=0 ;
    me.clear();
    en.clear();
    for(int i=1;i<=n;i++)t[i].clear(),e[i].clear(),dfn[i]=0,low[i]=0,insta[N]=0,bel[i]=0,scc[i].clear(),din[i]=0,sum[i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>o[i].l>>o[i].x>>o[i].r>>o[i].y;
        int num = o[i].x+o[i].y;
        o[i].num=num;
        o[i].id=i;
        if(num==2)ans[++it]=i;
        else if(num==4)en.push_back(i);
        else if(num==3)
        {
            int u ,v;
            if(o[i].x<o[i].y)u=o[i].l,v=o[i].r;
            else u=o[i].r,v=o[i].l;
            t[u].push_back(v);
            e[u].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++)
    {
         int u =i ;
         for(int j = 0; j<t[u].size();j++)
         {
             int v = t[u][j];
             if(bel[u]!=bel[v])din[bel[v]]++;
         }
    }
//     for(int i = 0 ;i<en.size();i++)
//     {   
//         int id = en[i];
//         int u = o[id].l;
//         int v = o[id].r;
// // cout<<"YES2"<<'\n';
//         if(din[bel[u]]==0 && me[u]==0  )dfs(u);
//         u=v;
//         //  cout<<"YES3"<<'\n';
//         if(din[bel[u]]==0 && me[u]==0  )dfs(u); 
//     }
    for(int i = 0 ;i<en.size();i++)
    {   
        int id = en[i];
        int u = o[id].l;
        int v = o[id].r;
// cout<<"YES2"<<'\n';
        din[bel[u]]==0 ;
        din[bel[v]]==0 ;
        //  cout<<"YES3"<<'\n';
      
    }
    
    for(int i=1;i<=n;i++)
    {
        if(din[bel[i]]==0 && me[i]==0  )dfs(i);
    }
    while(ans2.size())
    {
        ans[++it]=ans2.back();
        ans2.pop_back();
    }
    for(auto id : en)ans[++it]=id;
    for(int i= 1 ;i<=it ;i++)
    {
        int id = ans[i];
        sum[o[id].l] = o[id].x;
        sum[o[id].r]=o[id].y;
    }
    int ma =0 ;
    for(int i=1;i<=n;i++)ma+=sum[i];
    cout<<ma<<'\n';
    for(int i= 1;i<=m;i++)cout<<ans[i]<<' ';
    cout<<'\n';


}



signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
    // te();
}