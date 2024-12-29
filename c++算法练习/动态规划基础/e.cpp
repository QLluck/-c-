#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N = 1e7+7 ;
ll dp[N]={0} ;
int v[N]={0} ;
int w[N]={0} ;
void solve()
{
     int t,n;
     cin>>t>>n ;
     
     for(int i = 1 ;i<=n ;i++     ) cin>>w[i]>>v[i] ;

     for(int i = 1 ; i<=n ; i++) 
       for(int j = w[i] ; j<=t ;j++)
         dp[j]=max(dp[j] , dp[j-w[i]] + v[i]) ;
         cout<<dp[t]<<'\n' ;
    
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}