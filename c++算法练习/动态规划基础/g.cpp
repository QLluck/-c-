#include<bits/stdc++.h>
const int N = 1e4+7 ;
int dp[N]={0} ;
int t[N]={0} ;
int s[N]={0} ;
void solve()
{
   int n,m ;
   std::cin>>m>>n ;
   for(int i = 1 ; i <=n ;i++) std::cin>>s[i]>>t[i];
   for(int i = 1 ; i<=n ;i++)
    for(int j = t[i]  ;  j <= m ; j++)
          dp[j]=std::max(dp[j],dp[j-t[i]] + s[i]) ;   
    std::cout<<dp[m]<<'\n' ;      
    
}
int main()
{
    std::ios::sync_with_stdio(0),std::cout.tie(0),std::cin.tie(0) ;
    solve() ;

}