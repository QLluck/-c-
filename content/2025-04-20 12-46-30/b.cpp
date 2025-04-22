#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7 ;
int h[N]={0},it;

struct node 
{
     int u,v,h;
      
};
int c[N]={0};
int di[N]={0};
node tu[N*4];
pair<int,int> pai[N];
int pit;
void add(int u,int v)
{
     tu[++it].v=v ;
     tu[it].h=h[u];
     tu[it].u=u;
     h[u]=it;
}
int bfs(map<int,int>&mp)
{
    queue<int>que;
    map<int,int>me;
    que.push(1);
    me[1]=1;
    int num = 0 ;
    while(!que.empty())
    {
        int u = que.front();
         que.pop();
         int res=0;
         for(int i =  h[u];i!=0 ;i=tu[i].h)
         {
            if(me.count(tu[i].v))continue;
            me[tu[i].v]=1;
            que.push(tu[i].v);
            c[tu[i].v]=c[u]+1;
            res++;
         }
         if(res==0)

         {
            num++;
            mp[u]=1;
         }
    }
    return num;
}
void bfs2(int x ,map<int,int>&mp)
{
   queue<int> que;
   que.push(x);
   map<int,int> me ;
   me[x]=1;
   di[x]=1;
  // cout<<x<<"----------"<<'\n';
   while(!que.empty())
   {
      int  u = que.front();
      que.pop();
      
      for(int i = h[u];i!=0;i = tu[i].h)
      {
        if(me.count(tu[i].v)||c[u]<=c[tu[i].v])continue;
        me[tu[i].v]=1;
        que.push(tu[i].v);
          di[tu[i].v]+=1;
     
      // cout<<tu[i].v<<' '<<di[tu[i].v]<<'\n';
   
        
      }
   }

}
void solve()
{int n ;
    pit=0;
    c[1]=1;
    cin>>n;
    it=0;
    for(int i =1; i<=n;i++) 
    { h[i]=0;
        di[i]=0;
    }
    for(int i =1; i<=n-1;i++)
    {
         int u,v;
         cin>>u>>v;
         add(u,v);
         add(v,u);

    }
    map<int,int>mp;
    
    ll num = 0 ;
    num = bfs(mp);

    for(int i =1; i<=n;i++)
    {
        if(mp.count(i))
        { bfs2(i,mp);
       
        }
    }

    int q; 
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
     ll ans=(ll)di[a]*di[b]  ;
     cout<<ans<<'\n';
    
    
}
//for(int i =1 ;i<=n;i++)cout<<di[i]<<'\n';
    

 
     
}
int main()
{
    
    
    int t; 
   // cout<<"YES"<<'\n';
    scanf("%d",&t);
    while(t--)
    solve();
}