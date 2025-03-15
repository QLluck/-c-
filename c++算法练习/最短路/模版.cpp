#include<iostream>
#include<vector>
#include <utility>
#include<queue>
#include<map>

using namespace std;
const int N = 3e4 + 7;
const int inf = 1e9 + 7;
struct edge{
    int v, w;
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
               que.push(make_pair(-d[u], v));
             } 
         }
    }
 }
void solve()
{
    int m;
    cin>>n >> m;
  for(int i =1 ;i<=m ;i++)
  {
      int a ,b,c;
      cin>>a>>b>>c;
      edge temp;
      temp.v=b;
      temp.w=c;
      e[a].push_back(temp);
  }
    disk(1);
    cout << d[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}