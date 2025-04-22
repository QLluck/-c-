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
int me[N]={0};
//int mp[N]={0},itm;

void add(int u,int v)
{
     tu[++it].v=v ;
     tu[it].h=h[u];
     tu[it].u=u;
     h[u]=it;
}
int n ;

int bfs()
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
             
             di[u]=1;
         }
        // cout<<2<<'\n';
    }
    return num;
}

// void bfs2(map<int,int>&mp)
// {
//    queue<int> que;
//    map<int,int>me;
//    for(int i =1; i<=n;i++)
//    {
//      if(mp.count(i))
//      { que.push(i);
//         me[i]=1;
//         di[i]=1;
//      }

//    }
  

//   // cout<<x<<"----------"<<'\n';
//    while(!que.empty())
//    {
//       int  u = que.front();
//       que.pop();
      
//       for(int i = h[u];i!=0;i = tu[i].h)
//       {
//         if(c[u]<=c[tu[i].v])continue;
//         if(me[tu[i].v])
//         {
//              if(bu[u]+1==bu[tu[i].v])di[tu[i].v]+=di[u];
//              else if(bu[u]+1>bu[tu[i].v])
//              {

//              }
//         }
//         me[tu[i].v]=1;
//         que.push(tu[i].v);
//         bu[tu[i].v]=bu[u]+1;
//           di[tu[i].v]+=1;
     
//       // cout<<tu[i].v<<' '<<di[tu[i].v]<<'\n';
   
        
//       }
//    }

// }
int dfs( int x )
{   // cout<<"YYY"<<'\n';
     if(di[x])return di[x];
    int sum=0;
      for(int i = h[x];i!=0;i=tu[i].h)
      { // cout<<1<<'\n';
         if(me[tu[i].v])continue;
        me[tu[i].v]=1;
        
         sum+=dfs(tu[i].v);
         
      }
      return di[x]=sum;
}
void solve()
{
    
    c[1]=1;
    cin>>n;
    it=0;
    for(int i =1; i<=n;i++) 
    { h[i]=0;
        di[i]=0;
        me[i]=0;
       
    }
    for(int i =1; i<=n-1;i++)
    {
         int u,v;
         cin>>u>>v;
         add(u,v);
         add(v,u);

    }
   
    
    ll num = 0 ;
    num = bfs();
    me[1]=1;
   // cout<<"YES"<<'\n';
dfs(1);
  


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
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    
    int t; 
   // cout<<"YES"<<'\n';
    cin>>t;
    while(t--)
    solve();
}