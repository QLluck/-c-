#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7 ;
int dp1[N]={0} ;
int dp2[N]={0} ;
int vin[N]={0} ;
int viy[N]={0} ;
int w[N]={0} ;
void solve()
{
   int n,x ;
   cin>>n>>x; 

   for(int i = 1 ; i<=n ; i++)
   {
       cin>>vin[i]>>viy[i]>>w[i] ;
   }
   for(int i = 1 ; i<= n ;i++)
   {
      for(int j = 1 ;j <=x ;j ++)
     {
          dp2[j]=dp1[j] + vin[i];
          if(j>=w[i])
          {
             dp2[j]=max(dp1[j] +vin[i],  dp1[j-w[i]] +viy[i] ) ;
          }
     }
     for(int j = 1 ; j<=x ;j++) dp1[j]=dp2[j] ;

   }
   long long ans =(long long ) dp2[x]*5 ;
   
   cout<<ans<<'\n' ;


}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
   int t;
   solve() ;
}