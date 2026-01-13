#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII  pair<int,int> 
#define fi first 
#define se second 
const int N = 3e6+7;
const int INF = 1e17+7;
int a[N];
vector<int> t[N];
int g[N];
int en[N];
int d[N];
vector<int> we[N];
  map<PII,int> mp;
int it = 0 ;


void bfs(int s)
{
    priority_queue<PII>que;
    que.push({0,s});
    d[s]=0;
    while(que.size())
    {
        int u  = que.top().se;
        que.pop();
        for(int i =0 ; i<t[u].size();i++)
        {
            int v = t[u][i];
            int f = g[u];
            int id ;
            if(u>v)id=mp[{v,u}];
            else id = mp[{u,v}];
            int w  ;
             if(we[id].size()<=f)w=-INF;
            else w = we;

        }
        

    }
}
void debug(int x)
{
    cout<<"------\n";
    cout<<x<<'\n';
    cout<<"------\n";
}
void solve()
{
   
   int n,m,k;
   cin>>n>>m>>k;
   int it =0 ;
 
   for(int i=1;i<=k;i++)cin>>en[i];
   mp.clear();
   for(int i=1;i<=n;i++)cin>>g[i],d[i]=INF,we[i].clear(),t[i].clear();
   for(int i=1;i<=m;i++)
   {
    int u,v,w;
    cin>>u>>v>>w;
    if(u>v)swap(u,v);
    int id ;
    if(mp[{u,v}]==0)
     {   id=++it;
        mp[{u,v}]=id;
        t[u].push_back(v);
        t[v].push_back(u);
        we[id].push_back(w);
     }
     else we[id].push_back(w);
    
   
    
    // we[id].push_back(w);
   }
   for(int i = 1; i<=it ;i++)
   {
    sort(we[i].begin(),we[i].end());
   }
   bfs(1);

   


   
}
int f(int x)
{
    PII a[11];
    for(int i=1;i<=9;i++)a[i].fi=0,a[i].se=i;
    while(x)
    {
         a[x%10].fi+=1;
         x/=10;
    }
    sort(a+1,a+9+1);
    return a[9].se;
}
void te()
{
    int n;
    cin>>n;
    int ans =0 ;
    for(int i=1;i<=n;i++)
    {
    ans +=f(i);
    }
    cout<<ans<<'\n';
}
signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  t =1;
  cin>>t;
  while(t--)
  solve();
    // te();
}