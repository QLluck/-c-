#include<bits/stdc++.h>
using namespace std ;
const int N =1e3+7 ;
int dp1[N][N]={0} ;
int dp2[N][N]={0} ;
int w[N]={0} ;
int v[N]={0} ;
int vi[N]={0} ;
void solve()
{
   int h,t ;
   cin>>h>>t; 
   int n;
   cin>>n ;
   for(int i = 1 ; i<=n ;i++)cin>>v[i]>>w[i]>>vi[i] ;
   for(int i = 1 ; i<=n ;i++)
   { 
     for(int j = 1 ; j<=h ; j++)
     {   for(int g = 1 ; g<=t ;g++)
     {
         dp2[j][g] =dp1[j][g] ; 
         if(g>=w[i]&&j>=v[i])
         {
              dp2[j][g]=max(dp2[j][g],dp1[j-v[i]][g-w[i]] +vi[i]) ;
         } 
     }
     }
     for(int j = 0 ; j<=h ;j++)
     {
        for(int g = 0 ; g <=t ;g++)
        {
          dp1[j][g] = dp2[j][g] ;
        }
     }

   }
     cout<<dp2[h][t]<<'\n' ;


 


}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
   int t;
   solve() ;
}