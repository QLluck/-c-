#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+7 ;
const int P =998244353 ;
vector<int> t[N];
int de[N]={0},fa[N][27]={0};
//lca
#define ll long long 
ll po(ll a ,ll b )
{   ll res =1  ; 
      while(b)
      {
           if(b&1) res=res*a%P;
           b>>=1 ;
           a=a*a%P;

      }
      return res ;
}
#define ll long long

void dfs(int u,int fat)
{
      de[u]=de[fat]+1; 
      fa[u][0]=fat;
      
      for(int i =1 ;i<=24 ;i++)
      {
         fa[u][i] = fa[fa[u][i-1]][i-1];

      }
      for( int i =  0 ; i<t[u].size() ;i++)
      if(t[u][i]!=fat) 
        dfs(t[u][i],u);
}
//map<int,int> mp;
int lca(int u,int v)
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
      scanf("%d",&n);
      for(int i = 1 ;i<n ;i++)
      {
          int x,y ;
        scanf("%d %d",&x,&y);
          
        //   t[y].push_back(x);
          t[x].push_back(y);
      }
    de[0]=-1 ;
     dfs(1,0);

     int m ;
     scanf("%d",&m);
    // cout<<"??"<<fa[2][0]<<'\n';
    // for(int i=0 ;i<t[4].size() ; i++)cout<<t[4][i]<<' ' ;
     for(int i = 1 ;i <=m ;i++)
     {  int x ,y ,k ;
         scanf("%d %d %d",&x,&y,&k);
         
          int a = lca(x,y);
      ll sum = 0 ; 
     // printf("%d %d %d\n",de[x],de[y],de[a]);
      for( int j =de[x] ; j >= de[a] ; j--)
      {
          sum= sum+ po(j,k)%P;
      }
      for( int j =de[y] ; j >= de[a] ; j--)
      {
          sum= sum+ po(j,k)%P;
      }
      sum=sum - po(de[a],k) ;

          printf("%lld\n",sum);
     }


}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();

}