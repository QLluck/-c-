#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std ;
const int N = 1e5+7;
const int inf = 1e9+7;
int n,m,ans;
struct edge
{
     int u,v,w;
};
edge e[N];
int me[N]={0};
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
    for(int i =1 ; i<=m ;i++)
    {   
      //cout<<"find"<<e[i].u<<' '<<e[i].
          if(find(1)!=find(n))
          {    
              ans =e[i].w;
               me[find(e[i].u)]=find(e[i].v);

          }
          else return ;
          
    }
}



void solve()
{ 
   ans =0 ;
   cin>>n>>m;
   for(int i=1 ;i<=n ;i++)
   {
    me[i]=i;

   }
   for(int i =1 ;i<=m ;i++)
   {
      int a ,b,c;
      cin>>a>>b>>c;
      if(a>b)swap(a,b);

      e[i].u=a;
      e[i].v=b;
      e[i].w=c;
     
      
   }

   sort(e+1,e+m+1,cmp);
   dru();
   cout<<ans<<"\n\n";
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