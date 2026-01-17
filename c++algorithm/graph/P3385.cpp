#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 3e5+7;
const int INF = 1e9+7;
int h[N],cnt;
int n,m;
struct node
{
    int v,w,next;
    // node(int v,int w,int next):v(v),w(w){}
}e[N];
queue<int > que;
bool inque[N];
int d[N];
int cn[N];
void add(int u,int v,int w)
{
    e[++cnt]={v,w,h[u]};
    h[u]=cnt;
}
bool spfa()
{

  que.push(1);
  d[1]=0;
  inque[1]=1;
  cn[1]++;

    while(que.size())
    {
        int u =que.front();
        // cout<<d[u]<<' '<<u<<'\n'; 
        que.pop();
        inque[u]=0;
        for(int i = h[u] ; i!=0 ;i=e[i].next)
        {
            int v = e[i].v;
            int w = e[i].w;
            // cout<<v<<' '<<w<<'\n';
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                if(!inque[v])
                {
                    cn[v]++;
                    que.push(v);
                    inque[v]=1;
                    // cout<<u<<' '<<v<<' '<<d[v]<<' '<<cn[v]<<'\n';
                    if(cn[v]>n)return 1;

                }


            }

        }
    }
    return 0;
}
void solve()
{
     
     cin>>n>>m;
        cnt=0;
    while(que.size())que.pop();
     for(int i=1;i<=n;i++)h[i]=0,inque[i]=0,cn[i]=0,d[i]=INF;
     for(int i=1;i<=m;i++)
     {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        if(w>=0)add(v,u,w);
     }
   
        if(spfa())cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
     
 
     
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)solve();
}