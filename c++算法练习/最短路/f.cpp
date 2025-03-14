#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std ;
const int N = 1e5+7;
const int inf = 1e9+7;
int n,m;
struct edge
{
     int u,v,w;
     int b  ;
};
edge e[N];
int me[N]={0},it;
vector<edge> arr[1007]; 
bool cmp(edge a,edge b )
{
     return a.w>b.w;
}
int find(int x )
{
      if(me[x]==x)return x;
      else return me[x]=find(me[x]);
}
void dru()
{
    for(int i =1 ; i<=it ;i++)
    {
          if(find(e[i].u)!=find(e[i].w))
          {
                e[i].b=1;
               me[find(e[i].u)]=find(e[i].w);

          }
          
    }
}


queue<int> que;
void bfs()
{
   que.push(1);
   me[arr[1][0].u]=arr[1][0].w;
   for(int i =1; i<=n ;i++)me[i]=inf;
   while(!que.empty())
   {
        int u = que.front();
        que.pop();
        for(int i =0 ; i<arr[u].size();i++)
        {       int v = arr[u][i].v;
                int w=  arr[u][i].w;
            if(me[v]!=inf)continue ;
            me[v]=min(w,me[u]);
            que.push(v);
           // cout<<v<<'\n';    
            
        }

   }
}
void solve()
{  it = 0 ;
  
   cin>>m>>n;
   for(int i=1 ;i<=n ;i++)
   {arr[i].clear();
    me[i]=i;
   

   }
 
   
   for(int i =1 ;i<=m ;i++)
   {
      int a ,b,c;
      cin>>a>>b>>c;
      if(a>b)swap(a,b);

      e[++it].u=a;
      e[it].v=b;
      e[it].w=c;
      e[it].b=0;
      
   }
   sort(e+1,e+it+1,cmp);
   dru();
 
   for(int i =1 ;i<=it ;i++)
   {
      if(e[it].b==1)
      {
          arr[e[i].u].push_back(e[i]);

      }
   }
   bfs();
   cout<<me[n]<<'\n';
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     cin>>t;
     for(int i =1 ;i<=t ;i++)
  {   cout<<"Scenario #"<<i<<":\n";
     solve();
  }
}