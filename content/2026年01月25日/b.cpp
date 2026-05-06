#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e6+7;

int nex[N]={0};
int a[N];
vector<int> t[N];
map<PII,int>mp;
int d[N];
int dp[N];
void bfs(int s)
{
    queue<PII> que;
    que.push({s,0});
    map<int,int>me;
    me[s]=1;
    while(que.size())
    {
        int u = que.front().fi;
        int ud = que.front().se;
        que.pop();
        d[ud]=max(d[ud],a[u]);
        for(int i= 0;i <t[u].size();i++)
        {
            int v = t[u][i];
            if(me[v])continue;
            me[v]=1;
            que.push({v,ud+1});

        }
    }
}
void solve()
{
    int n,m,k;
    mp.clear();
    
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)t[i].clear(),d[i]=0,dp[i]=0;
    // cout<<"YES1"<<endl;
    for(int i=2;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u==v||mp[{u,v}])continue;
        mp[{u,v}]=1;
        mp[{v,u}]=1;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    //  cout<<"YES1"<<endl;
    bfs(1);
    for(int i=1;i<=k;i++)
    {
        if(i==1)
        { dp[i]=0;
            continue;
        }
        if(i&1)dp[i]=dp[i-1];
        else 
        {
            int ma =0 ;
            
            ma=max(ma,d[i/2]);
          for(int j=1;j<i;j++)
          {
            ma =max(dp[i-j]+dp[j],ma);
          }
            dp[i]=ma;
        }

    }
    for(int i=1;i<=k;i++)cout<<dp[i]<<' ';
    cout<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)
    solve();
    // bao();
}