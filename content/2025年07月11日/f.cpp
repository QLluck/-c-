#include<bits/stdc++.h>
using namespace std;
const int N =1e5+7;

struct node
{
    int u,v,w,next;
};
node t[2*N];
int h[N]={0},cnt;
int yi[N]={0};
int vis[N]={0};
void insert(int u,int v,int w)
{
     t[++cnt].u=u;
     t[cnt].v=v;
     t[cnt].w=w;
     t[cnt].next=h[u];
     h[u]=cnt;
     //cout<<t[u].u<<' '<<t[u].v<<' '<<t[u].w<<'\n';
}
queue<int> que;
void bfs(int s)
{
que.push(s);
vis[s]=1;
yi[s]=0;
while(que.size())
{
     int u= que.front();
     que.pop();
     for(int i = h[u];i!=0;i=t[i].next)
     {
         int v = t[i].v;
         int w = t[i].w ;
        
        
        // cout<<i<<' '<<h[u]<<' '<<yi[u]<<' '<<w<<' ' <<yi[v]<<'\n';
         if(vis[v])continue;
        vis[v]=1;
         yi[v]=yi[u]^w;
         que.push(v);
         
     }
}
}

void solve()
{
    int n;
    cin>>n;
    for(int i =1; i<=n;i++)h[i]=0,vis[i]=0;
    cnt=0;
    for(int i =1; i<=n-1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        insert(u,v,w);
        insert(v,u,w);
    }
    bfs(1);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        int ans = yi[l]^yi[r];
        cout<<ans<<'\n';
    }
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}