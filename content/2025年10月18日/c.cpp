#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define se second 
#define fi first 
#define pii pair<int,int>
const int N = 3e5+7;
const int INF = 1e18 +7;
 int n,m;
vector<pii> a[N];
pii d[N];
void bfs()
{
    unordered_map<int,int>mp;
    priority_queue<pair<int,pair<int,pii> >> que;
    que.push({0,{1,{0,0}}} );
    d[1].fi=0;
    d[1].se=0;
    mp[1]=1;
    int ans = INF  ; 
    while(que.size())
    {
         int u = que.top().se.fi;
         int a1 = que.top().se.se.fi;
         int a2 = que.top().se.se.se;
         
         que.pop();
        // if(u==n)ans = min(ans,a1+a2);
         
         for(int i = 0 ; i<a[u].size();i++)
         {
            int v = a[u][i].fi;
            int w = a[u][i].se;
   
            int b[4]={0,a1,a2,w};
            sort(b+1,b+3+1);
            if(d[v].fi+d[v].se>=b[2]+b[3])
            {  if(d[v].fi+d[v].se==b[2]+b[3])
                {
                    if(d[v].fi>b[3])
                    {
                                        d[v].fi=b[3];
                d[v].se=b[2];
                // cout<<v<<' '<<d[v]<<'\n';
            que.push({-b[3]-b[2],{v,{b[3],b[2]}}});
                    }
                }
                else 
                {
                d[v].fi=b[3];
                d[v].se=b[2];
                // cout<<v<<' '<<d[v]<<'\n';
            que.push({-b[3]-b[2],{v,{b[3],b[2]}}});
                }
            }
         }
    }
    // return ans;
}
void solve()
{
   
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
       
            int u,v,w;
            cin>>u>>v>>w;
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        
    }
    for(int i=1;i<=n;i++)d[i].fi=INF,d[i].se=INF;
     bfs();

    cout<<d[n].fi+d[n].se<<'\n';


}
// 4 1 2
//   3 
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}