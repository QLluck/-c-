#include<iostream>
#include<vector>
#include <utility>
#include<queue>
#include<map>

using namespace std;
const int N = 1e3 + 7;
const int inf = 1e9 + 7;
struct edge{
    int v, w;
};
struct node
{
    int ait, bit,w;
};
vector<edge> e[N];

int d[N] = {0}, me[N] = {0};
int n;
priority_queue<pair<int, int> > que;
void disk(int s )
{
    for (int i = 1; i <= n;i++)
        d[i] = inf;
    d[s] = 0;
    que.push(make_pair(0, s));
   
    while (!que.empty())
    {
         
         int u = que.top().second;
         que.pop();
         if(me[u])
                continue;
         me[u] = 1;
         for (int i = 0; i < e[u].size();i++)
         { 
             int v = e[u][i].v ;
             int w = e[u][i].w;
         
             if(d[v]>d[u]+w)
             {
                 d[v] = d[u] + w;
                if(!me[v]) que.push(make_pair(-d[u], v));
             } 
         }
    }
 }
void solve()
{
    int t;
    cin>>t >> n;

    map<pair<int, int>, node> mp;
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
      if(mp.count(make_pair(a,b)))
      {    
         if(c<mp[make_pair(a,b)].w)
         {
             int ait = mp[make_pair(a, b)].ait;
             int bit = mp[make_pair(a, b)].bit;
             e[a][ait].w = c;
             e[b][bit].w = c;
         }
              
      }
      else 
      {
          edge a1;
          edge b1;
          a1.v = b, a1.w = c;
          b1.v = a, b1.w = c;
          e[a].push_back(a1);
          e[b].push_back(b1);
          mp[make_pair(a, b)].w = c;
          mp[make_pair(a, b)].ait = e[a].size() - 1;
          mp[make_pair(a, b)].bit = e[b].size() - 1;

      }
        }
    disk(1);
    cout << d[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}