#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 5e5+7;

// int a[N][N];
int ans[N];
vector<int> t[N];
vector<int> tf[N];
vector<int> tt[N];
int d[N];
  int n,m,k;
void bfs()
{
    queue<int> que;
    for(int i=1;i<=n;i++)if(d[i]==0)que.push(i);
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for(int i=0;i<tf[u].size();i++)
        {
            int v = tf[u][i];
            d[v]--;
            if(d[v]==0)que.push(v);
        }

        int ma = ans[u] ;
        int sum =0 ;
        int f=0 ;
        for(int i=0 ;i<t[u].size();i++)
        {
            int v = t[u][i];
            if(ans[v]==-1)
            {
                f=1;
                break;
            }
            else ma=max(ans[v],ma);
            // if(i==t[u].size()-1)f=0;
            sum+=ans[v];
        }
        if(t[u].size()==0&&ans[u]==-1)f=-1;
         int mi =1e9+7;
        for(int i=0;i<tt[u].size();i++)
        {
            int v = tt[u][i];
           
           if(ans[v]!=-1)
           {  mi =min(ans[v]+1,mi);
             
           }
        //    cout<<mi<<" "<<ans[v]<<" "<<v<<" "<<u<<'\n';
          
        }
        //  cout<<' '<<ma<<' '<<ans[u]<<' '<<u<<'\n';
        if(mi!=1e9+7)
        {
                if(f)
                { 
                    ans[u]=mi;
                }
                else  ans[u]= min(sum,mi);
        }
        else 
        {
                if(f)
                { 
                    ans[u]=-1;
                }
                else  ans[u]= sum;
        }
        // ans[u]=ma;
        // cout<<f<<' '<<mi<<' '<<' '<<ma<<' '<<ans[u]<<' '<<u<<'\n';
    }
}
void solve()
{
   

  cin>>n>>m>>k;

  for(int i=1;i<=n;i++)ans[i]=-1,t[i].clear(),tf[i].clear(),d[i]=0,tt[i].clear();
  for(int i=1;i<=n;i++)
  {
    int num;
    cin>>num;
    d[i]+=num;
    for(int j=1;j<=num;j++)
    {   
        int v;
        cin>>v;
        t[i].push_back(v);
        tf[v].push_back(i);
    }
  }
  for(int i=1;i<=m;i++)
  {
    int u,v;
    cin>>u>>v;
    tt[u].push_back(v);
  }
  for(int i=1;i<=k;i++)
  {
    int x;
    cin>>x;
    ans[x]=0;
  }
  bfs();
  cout<<ans[1]<<'\n';

}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
    t=1;
    cin>>t;
    while(t--)
    solve();
}