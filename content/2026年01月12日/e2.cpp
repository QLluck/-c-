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
vector<int> e2[N];
int ans[N],it;
int ans1[N], it1;
map<PII, int> mp;
map<int, int> me;
stack<int> sta;
int dfn[N], low[N];
int cnt=0, cntb = 0;
vector<int> ya[N];
int yad[N];
PII dc[N];
map<int, int> me1;
map<int, int> me3;
int dfs(int u)
{
    if(me1[u])return dc[u].fi;
    me1[u] = 1;
    for (int i = 0; i <e2[u].size();i++)
    {
        int v = e2[u][i];
        if(!me1[v])dc[u].fi+=dfs(v);
    }
    return dc[u].fi;
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
           yad[node]=cntb;

       } while (node != u);
   }
}
void bfs(int s)
{
    queue<int> que;
    que.push(s);
    map<int, int> me;
    me[s]=1;
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < e[u].size();i++)
        {
            int v = e[u][i];
            if(me[v])
                continue;
                me[v]=1;
            ans1[++it1] = mp[{u, v}];
            isn[v] = 2;
            que.push(v);
        }
    }
}
 bool so(node a,node b)
 {
    return a.num<b.num;
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
        isn[i] = 0, e[i].clear(),dfn[i]=0,low[i]=0,ya[i].clear(),yad[i]=0;
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
        dc[i].fi = ya[i].size(),dc[i].se=i;
    map<PII,int>me4;
    for(int i=1;i<=cntb;i++)
    {
        for(int j=0;j<ya[i].size();j++)
        {
             int u = ya[i][j];
             for(int h =0 ;h<e[u].size();h++)
             {
                int v = yad[e[u][h]];
                if(i==v || me4[{i,v}])continue;
                me4[{i,v}]=1;
                e2[i].push_back(v);
             }
        }
    }
        for (int i = 1; i <= cntb; i++)
        {
            if (!me1[i])
                dfs(i);
        }
        sort(dc+1, dc + cntb + 1);
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
        sort(o+1,o+m+1,so);
        for (int i = it1; i >= 1; i--)
        {
            // ans[++it] = ans1[i];
            me2[ans1[i]] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            if(o[i].num==2)
            {
                isn[o[i].l]=max(o[i].x,isn[o[i].l]);
                isn[o[i].r]=max(o[i].y,isn[o[i].y]);
               
            }
            else if (me2[i] == 0 && o[i].num == 3)
                ans[++it] = o[i].id;
        }
      
        for (int i = it1;i>=1; i--)
          {  ans[++it] = ans1[i];
              
          }
          for (int i = 1; i <= m;i++)if(o[i].num==4)
                  ans[++it] = i;
          int sum = 0;
          for (int i = 1; i <= n;i++)
              sum += isn[i];
          cout << sum << '\n';
          for (int i = 1; i <= it;i++)
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