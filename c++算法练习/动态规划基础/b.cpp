#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7 ;
int dp1[N]={0} ;
int dp2[N]={0} ;
int vi[N]={0} ;
int w[N]={0} ;
void solve()
{
   int n,m ;
   cin>>n>>m ;
   for(int i = 1 ; i<=m ;i++)
   {
      int a,b ;
      cin>>a>>b ;
      vi[i] = a*b ;
      w[i] = a ;
   }
   for(int i  = 1; i<= m ;i ++)
   {
      for(int j = 1 ;j<=n ; j++)
      {
        dp2[j]=dp1[j] ;
        if(j>= w[i] )
        {
             dp2[j]= max(dp2[j],dp1[j-w[i]] + vi[i]) ;
        }
      }
      for(int j = 1 ;j<=n ; j++)
      {
          dp1[j]=dp2[j] ;
      }

   }
   cout<<dp2[n]<<'\n' ;

}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
   int t;
   solve() ;
}