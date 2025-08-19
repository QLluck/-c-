#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi  first
#define se second
const int N =1e6+7;
const int INF =1e18+7;

const int P =998244353;

int dp[N]={0};
int w[N]={0};
int s[N]={0};
vector<int> t[N];
vector<int> qu[N] ;
map<pii,int>mp;
map<int,int>mp2;
map<int,int>mp3;
map<pii,int> zu;
pii qq[N];
int me[N];
int find(int x)
{
    if(me[x]==x)return x;
    else return me[x]=find(me[x]);
}
queue<int> que;
void bfs()
{
   que.push(1);
   map<int,int>mp1;
   mp1[1]=1;
   s[1]=w[1];
   while(que.size())
   {
       int u = que.front();
       que.pop();
       for(int i= 0 ;i < t[u].size();i++)
      {
           int v =  t[u][i];
           if(mp1[v])continue;
           mp1[v]=1;
           s[v] = w[v] +s[u];
           que.push(v);

      }
   }
}
void dfs(int u)
{   mp3[u]=1;
    for(int i =0 ; i<t[u].size() ;i++)
    {  if(mp3[t[u][i]])continue;
       // mp2[t[u][i]]=1;
        dfs(t[u][i]);
        me[t[u][i]] = u;
    }

    for(int i=0;i<qu[u].size();i++)
    {  int v = qu[u][i];
        if(mp3[v])
        {
            int ans = find(me[v]);
            mp[{u,v}]=ans;
            mp[{v,u}]=ans;
        }
    }

}
 void solve()
 {
     
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>w[i],me[i]=i;
   for(int i=1;i<n;i++)
   {
    int u,v;
    cin>>u>>v;
    t[u].push_back(v);
    t[v].push_back(u);

   }
   int q;
   cin>>q;

   for(int i=1;i<=q;i++)
   {
    int k;
    cin>>k;
    int u,v;
    cin>>u>>v;
    qq[i].fi = u;
    qq[i].se =v;

    if(mp[{u,v}])continue;
    else 
    {
        mp[{u,v}]=1;
        mp[{v,u}]=1;
        qu[u].push_back(v);
        qu[v].push_back(u);
       
    }

   
   }
       bfs();
   dfs(1);
   for(int i=1;i<=q;i++)
   {
     int u = qq[i].fi;
     int v = qq[i].se;
     cout<<mp[{u,v}]<<'\n';
     int ans=  s[u]+s[v] -s[mp[{u,v}]];
     cout<<ans<<'\n';
   }


 }
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}