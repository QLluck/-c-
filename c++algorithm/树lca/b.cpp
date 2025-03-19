#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
using namespace std ;
const int N = 1e4+7 ;

//lca
void dfs(int u,int fat,int de[],int fa[][27],vector<int> t[])
{
      de[u]=de[fat]+1; 
      fa[u][0]=fat;


    // cout<<u<<'\n';
    // cout<<fa[2][0]<<'\n' ;
   
      
      for(int i =1 ;i<=24 ;i++)
      {
         fa[u][i] = fa[fa[u][i-1]][i-1];

      }
    //   if(u==2)
    //      {
    //           cout<<"YES"<<'\n';
    //      }
    // cout<<"-----"<<'\n';
      for( int i =  0 ; i<t[u].size() ;i++)
      if(t[u][i]!=fat)
        dfs(t[u][i], u, de,fa,t);
}
//map<int,int> mp;
int lca(int u,int v,int de[],int fa[][27])
{     
      if(de[u]<de[v])swap(u,v);
      for (int i =24 ; i>=0 ;i--)
      {
          if(de[fa[u][i]]>=de[v])
            u = fa[u][i];
            
      }


      if(u==v)return v ;
      for (int i =24 ; i>=0 ; i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];


            return fa[u][0];

}
// int dian(int n )
// {
//      for(int i =1 ;i<=n ;i++)if(!mp.count(i)) return i;
//      return 0 ; 
// }

void solve()
{
  int n;
  map<int, int> mp;
  vector<int> t[N];
  int de[N] , fa[N][27];
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    t[y].push_back(x);
    t[x].push_back(y);
    mp[y] = 1;
      }
      int s = 1;
      while(mp.count(s))
        s++;

      dfs(s, 0,de,fa,t);

      // cout<<"??"<<fa[2][0]<<'\n';
      // for(int i=0 ;i<t[4].size() ; i++)cout<<t[4][i]<<' ' ;
     
      int x ,y ;
         scanf("%d %d",&x,&y);
         
          int a = lca(x,y,de,fa);
          printf("%d\n",a);
     


}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     scanf("%d", &t);
     while(t--)
     solve();

}