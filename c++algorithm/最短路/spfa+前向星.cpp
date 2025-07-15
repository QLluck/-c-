#include<iostream>
#include<stdio.h>
#include<stack>
#include<cstring>
using namespace std ;
const int N = 30010 ;
const int inf =1e9+7;
int n,m;
struct edge
{
   int v,w,next;
}e[150010];
int head[N]={0},cnt=1;
int d[N],me[N]={0},vis[N]={0};
void add(int u,int v ,int w)
{
  e[cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt++;

}
stack<int> sta;
void spfa(int s )
{
     memset(d,inf,sizeof(d));
     memset(vis,0,sizeof(vis));
     d[s]=0;
     vis[s]=1;
     sta.push(s);
     while(!sta.empty())
     {
        int u = sta.top();
        sta.pop();
        vis[u]=0;
        for (int i=head[u]; i!=-1 ; i=e[i].next)
        {
                int v = e[i].v;
                int w = e[i].w ;
                if (d[v]>d[u]+w)
              {  d[v]=d[u]+w;
               
                
                if(!vis[v])
                 { sta.push(v);
                    vis[v]=1;
                 }
                 
                }
        }
     }


}

void solve()
{  int s ;
  scanf("%d %d",&n,&m);
  memset(head,-1,sizeof(head));
  for(int i =1; i<=m  ;i++)
  {
      int u,v,w;
      scanf("%d %d %d",&u,&v,&w);
      add(u,v,w);

  }
  spfa( 1 );
   printf("%d",d[n]);

}

int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}
    
    