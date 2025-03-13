#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int N = 1e5 + 7;
struct edge{
    int v, w;
};
vector<edge> e[N];
int d[N] = {0};
int me[N] = {0};
int n;
priority_queue<pair<int, int>> que;
void disk(int s)
{
    for (int i = 1; i <= n;i++)
        d[i] = inf;
    d[s] = 0;
   
    que.push({0, s});
    while(!que.empty())
    {
        int u = que.top().second;
        que.pop();
        if(me[u])
            continue;
        me[u] = 1;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].v;
            int w = e[u][i].w;
            if( d[v]<=d[u]+w)
                continue;
            
            d[v] = d[u] + w;
           if(!me[v]) que.push({-d[v], v});
        }
    }
}
void solve()
{
    int m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m;i++)
    {
        int a, b, c;
        cin >> a>>b>>c;
        e[a].push_back({b, c});
    }
    disk(s);
    for (int i = 1; i <= n;i++)
        cout << d[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}