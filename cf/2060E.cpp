#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 3e5+7;
const int mod = 998244353;
int a[N];
int me2[N];
int me1[N];
 int n,m1,m2;
vector<int> t1[N];
vector<int> t2[N];
int ans= 0 ;
queue<int> que;

void bfs1(int s,vector<int> t[],int me[]);
void Bji(vector<int> t[],int me[]);
int find(int x,int me[]);
int bfs3(int s,vector<int> t[],int me[])
{
    que.push(s);
    set<int> se;
    set<int> se2;
    se2.insert(s);
    se.insert(me1[s]);
     while(que.size())
     {
        int u =que.front();
        que.pop();
        for(int i=0;i<t[u].size();i++)
        {
            // int x = find(u,me);
            int v = t[u][i]; 
            // int y = find(v,me);
            if(se2.count(v))continue;
            se2.insert(v);
            se.insert(me1[v]);
            que.push(v);
            // cout<<v<<' '<<u<<' '<<x<<' '<<y<<' '<<me[v]<<'\n';
            //   cout<<"-----"<<' '<<u<<' '<<v<<' '<<me1[v]<<'\n';

        }
     }
     return se.size()-1;
}
void bfs1(int s,vector<int> t[],int me[])
{
    que.push(s);
    // set<int> se;
    // se.insert(s);
     while(que.size())
     {
        int u =que.front();
        que.pop();
        for(int i=0;i<t[u].size();i++)
        {
            int x = find(u,me);
            int v = t[u][i]; 
            int y = find(v,me);
            //cout<<v<<' '<<u<<' '<<x<<' '<<y<<' '<<me[v]<<'\n';
            // if(se.count(v))continue;
            // se.insert(v);
            if(x!=y)
            {
                me[v]=x;
                
                que.push(v);
            }
        }
     }
}
void bfs2(int s,vector<int> t[],int me[])
{
     que.push(s);
    //  set<int> se;
    //  se.insert(s);
     while(que.size())
     {
        int u =que.front();
        que.pop();
        for(int i=0;i<t[u].size();i++)
        {
            int x = find(u,me2);
            int v = t[u][i]; 
            int y = find(v,me2);
            int x1 = find(u,me1);

            int y1 = find(v,me1);
            // if(se.count(v))continue;
            // se.insert(v);
            if(x!=y)
            {
                // me[v]=x;
                
                // que.push(v);
                ans++;
                // cout<<"-----"<<' '<<u<<' '<<v<<'\n';

            }
            else 
            { if(x1!=y1)
                {
                me[v]=x1;
                que.push(v);
                }
            }
        }
     }
}
void Bji(vector<int> t[],int me[])
{
    for(int i=1;i<=n;i++)
    {
        if(me[i]==i)bfs1(i,t,me);
    }
}
int find(int x,int me[])
{
     if(x==me[x])return x;
     else return me[x]=find(me[x],me);
}
void solve()
{
   ans=0;
  
   cin>>n>>m1>>m2;
   for(int i=1;i<=n;i++)me1[i]=i,me2[i]=i,t1[i].clear(),t2[i].clear();
   for(int i=1;i<=m1;i++)
   {
    int u,v;
    cin>>u>>v;
    t1[u].push_back(v);
    t1[v].push_back(u);
   }
   for(int i=1;i<=m2;i++)
   {
    int u,v;
    cin>>u>>v;
    t2[v].push_back(u);
    t2[u].push_back(v);
   }
   Bji(t2,me2);
//    for(int i=1;i<=n;i++)cout<<i<<' '<<me2[i]<<'\n';  
   for(int i=1;i<=n;i++)
   {
    if(me1[i]==i)bfs2(i,t1,me1);
   }
//    int ans=0 ;
//    for(int i=1;i<=n;i++)cout<<me1[i]<<' ';
//    cout<<'\n';
   ans/=2;
//  cout<<ans<<'\n';
 
   for(int i=1;i<=n;i++)
   {
      if(me2[i]==i)
      {
        ans+=bfs3(i,t2,me2);
      }
   }
   cout<<ans<<'\n';
    

}


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
