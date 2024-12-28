#include<bits/stdc++.h>
using namespace std ;
const int N =1e3+7 ;
int dp1[N]={0} ;
int dp2[N]={0} ;
int ti[N]={0} ;
int vi[N]={0} ;
void solve()
{
      int t;
      int n ;
      cin>>t>>n ;
      for(int i = 1 ; i<=n ;i++) 
      {
         cin>>ti[i]>>vi[i] ;
      }
      for(int i = 1 ; i<= n ; i++)
      {    
          for(int j = 1 ; j<=t ; j++)
          {
              dp2[j]=dp1[j] ;
              if(j>=ti[i])
              {
                 dp2[j]=max(dp2[j],dp1[j-ti[i]] + vi[i]  ) ;
              }
          }
          for(int j = 1 ; j<=t ;j++)
          {
             dp1[j]=dp2[j] ;
          }
      }
      cout<<dp2[t]<<'\n' ;


}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
   int t;
   solve() ;
}