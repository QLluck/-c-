#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7;
struct node
{
    int u, v;
    int next;
};
int me[N]={0};
node e[N*4]={0};
int h[N]={0},it;
struct node2
{
     int v,s;
};
queue<node2> que;
void bfs(int st,int st1)
{   node2 temp ={st,1};
   que.push(temp);
   me[st]=0;

   while(que.size())
   {
       node2 u = que.front();
       que.pop();
       for(int i = h[u.v];i!=0 ; i = e[i].next)
       {
            int v = e[i].v;
            int s = u.s+1;
            if(!me[v])continue;
            me[v]=0;
            if(s&1)cout<<v<<' '<<u.v<<'\n';
            else cout<<u.v<<' '<<v<<'\n';
             node2 temp1 ={v,s};
            que.push(temp1);

            
       }

   }
    temp.s =2 ;
    temp.v=st1;
      que.push(temp);
   me[st1]=0;

   while(que.size())
   {
       node2 u = que.front();
       que.pop();
       for(int i = h[u.v];i!=0 ; i = e[i].next)
       {
            int v = e[i].v;
            int s = u.s+1;
            if(!me[v])continue;
            me[v]=0;
            if(s&1)cout<<v<<' '<<u.v<<'\n';
            else cout<<u.v<<' '<<v<<'\n';
             node2 temp1 ={v,s};
            que.push(temp1);

            
       }

   }


}
void insert(int u,int v)
{
     e[++it].u=u;
     e[it].v=v;
     e[it].next=h[u];
     h[u]=it;


}
void solve()
{
int n;
cin>>n;
it=0;
for(int i =1; i<=n;i++)
{ h[i]=0;
    me[i]=0;
}
for(int i=1; i<n;i++)
{
    int u,v;
    cin>>u>>v;
    insert(u,v);
    insert(v,u);
    me[u]++;
    me[v]++;
}
int flag=0;
int st1 =0 ;
int st2 =0 ;
int st = 0;
for(int i =1; i<=n;i++)
{  
    if(me[i]==2)
    {    node u = e[h[i]];
        st1 = u.v;
        u=e[u.next];
        st2 =u.v;
        flag=1;
        st = i ;
        break;

    }
}
me[st]=0;
if(flag)cout<<"YES"<<'\n',cout<<st1<<' '<<st<<'\n',cout<<st<<' '<<st2<<'\n',bfs(st1,st2);
else cout<<"NO"<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
