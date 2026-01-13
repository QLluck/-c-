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
int isn[N];
vector<int> e[N];
int ans[N],it;
int ans1[N], it1;
map<PII, int> mp;
map<int, int> me;
stack<int> sta;
int dfn[N], low[N];
int cnt=0, cntb = 0;
vector<int> ya[N];
map<int, int> yad;
PII dc[N];
map<int, int> me1;
map<int, int> me3;
int dfs(int s)
{
    if(me1[s])return dc[s].se;
    me1[s] = 1;
    for (int i = 0; i <ya[s].size();i++)
    {
        int u = ya[s][i];
        for (int j = 0; j < e[u].size();j++)
        {
            int v = e[u][j];
           if( !(s==yad[v]) )
           {
               dc[s].se+= dfs(yad[v]);
           }
        }
    }
   
    return dc[s].se;
}
void tarjan(int u)
{
    sta.push(u);
    me[u] = 1;
    dfn[u] = low[u] = ++cnt;
    for (int i = 0; i < e[u].size();i++)
    {
        int v = e[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(me[v])
            low[u] = min(dfn[v], low[u]);
    }
   if(dfn[u]==low[u])
   {
       ++cntb;
       int node;
        do
       {
           node = sta.top();
           sta.pop();
           me[node] = 0;
           ya[cntb].push_back(node);

       } while (node != u);
   }
}
void bfs(int s)
{
    queue<int> que;
    que.push(s);
    map<int, int> me;
    
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < e[u].size();i++)
        {
            int v = e[u][i];
            if(me[v]||isn[v])
                continue;
            ans1[++it1] = mp[{u, v}];
            isn[v] = 2;
            que.push(v);
        }
    }
}
void solve()
{
    int n, m;
    it = 0;
    it1 = 0;
    cin >> n >> m;
    mp.clear();
    me.clear();
    me3.clear();
    cnt = 0, cntb = 0;
    for (int i = 1; i <= n;i++)
        isn[i] = 0, e[i].clear(),dfn[i]=0,low[i]=0,ya[i].clear();
        for (int i = 1; i <= m; i++)
        {
            o[i].id = i;
            cin >> o[i].l >> o[i].x >> o[i].r >> o[i].y;
            o[i].num = o[i].x + o[i].y;
        }
        
        for (int i = 1; i <= m; i++)
        {
            if (o[i].num == 2)
                ans[++it] = o[i].id;
            else if(o[i].num==3)
            {
                int u, v;
                if(o[i].x<o[i].y)
                    u = o[i].l, v = o[i].r;
                else
                    u = o[i].r, v = o[i].l;
                if(mp[{u,v}]==0)
                {
                    e[u].push_back(v);
                    mp[{u, v}] = o[i].id;
                }
                me3[u] = 1, me3[v] = 1;
            }
            else if(o[i].num==4)
                isn[o[i].l] = 2, isn[o[i].r] = 2;
            
    }
    for (int i = 1; i <= n;i++)
       if(!dfn[i]&&me3[i]) tarjan(i);
    for (int i = 1; i <= cntb;i++)
        dc[i].fi = ya[i].size(),dc[i].se;
        for (int i = 1; i <= cntb; i++)
        {
            if (me1[i])
                dfs(i);
        }
        sort(dc, dc + cntb + 1);
        for (int i = 1;i<=n;i++)
        {
                if(isn[i]==2)
                    bfs(i);
        
        }
        for (int i = cntb; i>=1;i--)
        {
            for (int j = 0; j < ya[i].size();j++)
            {
                int u = ya[i][j];

                    if(isn[u]==0)
                    {
                        isn[u] = 1;
                        bfs(u);
                    }
                
            }
        }
        map<int, int> me2;
        for (int i = it1; i >= 1; i--)
        {
            // ans[++it] = ans1[i];
            me2[ans1[i]] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            if (me2[i] == 0 && o[i].num == 3)
                ans[++it] = i;
        }
      
        for (int i = it1;i>=1; i--)
          {  ans[++it] = ans1[i];
              me2[ans1[i]] = 1;
          }
          for (int i = 1; i <= m;i++)if(o[i].num==4)
                  ans[++it] = i;
          int sum = 0;
          for (int i = 1; i <= n;i++)
              sum += isn[i];
          cout << sum << '\n';
          for (int i = 1; i <= m;i++)
              cout << ans[i] << ' ';
          cout << '\n';
        //   for (int i = 1; i <= n;i++)
        //       cout << isn[i] << ' ';
        //   cout << '\n';
        //   cout << cntb << '\n';
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