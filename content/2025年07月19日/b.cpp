#include<bits/stdc++.h>
using namespace std;
#define int long long
#define se second
#define fi first
const int N =2e5+7;
const int INF = 1e18+7;

vector<pair<int ,int > > t[N];
map<pair<int,int> ,int > mp ;
int d[N]={0};
void dj()
{
    priority_queue<pair<int,pair<int,int> > > que;
    que.push({0,{1,0}});
    d[1]=0;
    mp[{1,0}]=1;
    while(que.size())
    {
          int w = que.top().fi ;
          int u = que.top().se.fi;
          int f = que.top().se.se;
        
          que.pop();
          for(int i = 0; i<t[u].size() ; i++)
          {
               int v1 = t[u][i].fi;
               int f1 = t[u][i].se ;
               int w1 = (f==f1)?0:1;
            if(mp[make_pair(v1,f1)])continue;
        mp[make_pair(v1,f1)]=1;
            if(d[v1]>=d[u]+w1)
            {
                 d[v1] = d[u]+w1;
                 que.push({-d[v1],{v1,f1}});
            }

          }
    }
}
void solve()
{
   int n,m;
   cin>>n>>m;
   for(int i =1;i<=n;i++)t[i].clear(),d[i]=INF;
   mp.clear();
   for(int i =1;i<=m;i++)
   {
      int u,v,f;
      cin>>u>>v>>f;
      t[u].push_back({v,f});
      t[v].push_back({u,f});
   }
   dj();
   cout<<d[n]<<'\n';


}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   solve();
}