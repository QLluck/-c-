#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5+7;
const int INF =1e9+7;

int h[N]={0},cnt;
int d[N]={0};
int d2[N]={0};
int vis[N]={0};
int e[1007][1007]={0};

vector<int> vr[1003];
priority_queue<pair<int,int > > que;
void dj(int n,int s )
{ 
     for(int i =1; i<=n;i++)
     {
        d[i]=INF;
        vis[i]=0;
     }
     vis[s]=1;
     d[s]=0;
     que.push(make_pair(-d[s],s));
     while(que.size())
     {
          int u = que.top().second;
          que.pop();
          vis[u]=1;
         //cout<<1<<'\n';
          for(int j = 0 ; j <vr[u].size() ; j ++)
          {      int i = vr[u][j];
            if(i==u)continue; 
             if(e[u][i]==0)continue;
             if(vis[i])continue;
              int w = e[u][i];
             if(d[i]>d[u]+w)d[i]=d[u]+w;
             que.push(make_pair(-d[i],i));
          }
     }

}
void dj2(int n,int s)
{
       for(int i =1; i<=n;i++)
     {
        d2[i]=INF;
        vis[i]=0;
     }
     vis[s]=1;
     d2[s]=0;
     que.push(make_pair(-d2[s],s));
     while(que.size())
     {
          int u = que.top().second;
          que.pop();
          vis[u]=1;
       //  cout<<1<<'\n';
          for(int j = 0 ; j <vr[u].size() ; j ++)
          {      int i = vr[u][j];
             if(i==u)continue;
             if(e[i][u]==0)continue;
             if(vis[i])continue;
              int w = e[i][u];
             if(d2[i]>d2[u]+w)d2[i]=d2[u]+w;
             que.push(make_pair(-d2[i],i));
          }
     }
}

void solve()
{
   
  int n,m,x;
  cnt =0 ;
  cin>>n>>m>>x;
  for(int i =1; i<=n;i++)h[i]=0;
  for(int i=1; i<=m;i++)
  {int u,v,w;

     cin>>u>>v>>w;
     if(e[u][v])
     {
     e[u][v]= min(w,e[u][v]);
     }
     else 
     {
       e[u][v]=w;
        vr[u].push_back(v);
        vr[v].push_back(u);
     }
  }
  dj(n,x);
  dj2(n,x);
  int ma= 0 ;
  for(int i =1; i<=n;i++)ma= max(d[i]+d2[i],ma);
  cout<<ma<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}