#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
struct node
{
     int u,v,w;
};
vector<node> t[N];
int c[N]={0};
int me[N]={0};
map<int,int> mp[N] ;
int r[N]={0};
int ans =0;
void bfs()
{   queue<int> que;

     que.push(1);
     me[1]=1;
     while(que.size())
     {
        int u = que.front();
        que.pop();
        for(int i =0 ;i<t[u].size() ; i++)
        {
              int v = t[u][i].v;
              int w = t[u][i].w;
              if(me[v])continue;
              me[v]=w ;
              r[v]=u;
              mp[u][0]+=w;
              mp[u][c[v]]+=w;
              if(c[v]!=c[u])ans+=w;
              que.push(v);

        }
     }
}
void solve()
{
     int n,q;
     cin>>n>>q;
     ans =0 ;
     for(int  i=1;i<=n;i++)
     {
          cin>>c[i];
          t[i].clear();
          me[i]=0;
          mp[i].clear();
          r[i]=0;
          
     }

     for(int i =1;i<=n-1;i++)
     {
        int u,v,w;
        cin>>u>>v>>w;
        node temp = {u,v,w};
        t[u].push_back(temp);
        temp.u=v;
        temp.v=u;
        t[v].push_back(temp);
     }
     bfs();
     for(int i =1; i<=q; i++)
     {
         int u,x;
         cin>>u>>x;
         if(c[u]!=x) 
          {ans -= mp[u][x];
           ans +=mp[u][c[u]];
          }
          cout<<"------------"<<'\n';
         cout<< mp[u][c[u]] <<' '<< mp[u][x]<<' '<<x<<' '<<u<<'\n';
         
         cout<<"-----------"<<'\n';
          int fa  = r[u];
          cout<<"FU"<<fa<<'\n';
          if(fa)
          {
            if(x!=c[fa]&&c[u]==c[fa])ans+=me[u];
          //  cout<<"11"<<' '<<me[u]<<'\n';
            if(x==c[fa]&&c[u]!=x) ans-=me[u];
            mp[fa][c[u]]-=me[u];
            mp[fa][x]+=me[u];



          }
           c[u]=x;
           cout<<ans<<'\n';

     }

}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int T;
   cin>>T;
   while(T--)
   solve();
}