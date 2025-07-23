#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define int long long
#define fi first
#define se second
const int INF = 1e18+7;
const int N =5e5+7;
vector<int> t[5007];
pair<int,int> d[N];
void bfs()
{
   priority_queue<pair<int,pair<int,int> > >que;
   que.push({0,{1,0}});
   d[1].fi = 0 ;
   d[1].se =0 ;
   while(que.size())
   {
       int time =  que.top().fi ;
       int u = que.top().se.fi;
       int stop = que.top().se.se;
       que.pop();
       int l = t[u].size();
       for(int i =0 ; i< l;i++)
       {
            int v1 = t[u][(time+i)%l];
            int t1 = time+i+1;
            int stop1 = stop+i;

            if(d[v1].fi >= d[u].fi +i+1 )
            {
                 if(d[v1].se >= d[u].se + i )
                 {
                     d[v1].fi = d[u].fi +i+1;
                     d[v1].se = d[u].se + i ; 
                     que.push({-d[v1].fi,{v1,d[v1].se}});
                 }
            }

       }
   }

}
void solve()
{
  int n,m;
  cin>>n>>m;
  for(int i =1;i<=n;i++)d[i].fi=INF,d[i].se=INF,t[i].clear();

  for(int i =1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    t[u].push_back(v);
    t[v].push_back(u);
  }
  bfs();
  cout<<d[n].fi<<' '<<d[n].se<<'\n';
  

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)

    solve();
}