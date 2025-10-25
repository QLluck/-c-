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
int d[N]={0};
struct node
{
    int w,v,a1,a2;
    
     const bool operator<( node   p)const
    {
        if(p.w!=w)return w>p.w;
        else 
        {
            if(p.a1!=a1)return a1>p.a1;
            else return a2>p.a2;
        }
    }
};
void bfs()
{
    unordered_map<int,int>mp;
    priority_queue<node> que;
    node s ;
    s.w=0;
    s.v=1;
    s.a1=0;
    s.a2=0;
    que.push(s);
    d[1]=0;
    mp[1]=1;
    int ans = INF  ; 
    while(que.size())
    {
         int u = que.top().v;
         int a1 = que.top().a1;
         int a2 = que.top().a2;
         
         que.pop();
        // if(u==n)ans = min(ans,a1+a2);
         
         for(int i = 0 ; i<a[u].size();i++)
         {
            int v = a[u][i].fi;
            int w = a[u][i].se;
   
            int b[4]={0,a1,a2,w};
            sort(b+1,b+3+1);
            if(d[v]>b[2]+b[3])
            {   d[v]=b[2]+b[3];
                cout<<v<<' '<<d[v]<<'\n';
                node tmp = {b[3]+b[2],v,b[3],b[2]};
            que.push(tmp);
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
    for(int i=1;i<=n;i++)d[i]=INF;
     bfs();

    cout<<d[n]<<'\n';


}
// 4 1 2
//   3 
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}