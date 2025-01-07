#include<bits/stdc++.h>
const int N = 1e5 + 7 ;
#define ll long long 
ll dp[N]={0} ;
ll v[N]={0},it ;
ll w[N]={0} ;

void solve()
{
     int n,W ;
     std::cin>>n>>W; 
     for(int i = 1 ;i <= n;i++)
     {
          ll a,b,c,k=1 ;

          std::cin>>a>>b>>c ;
          while(k<=c)
          {
              v[++it]= k*a;
              w[it]= k*b ;
              
                c-=k ;
                k*=2;
            
          }
          if(c)
          {
              v[++it] = c*a ;
              w[it] = c*b ;
          }
     }
     for(int i = 1; i<=it ;i++)
       for(int j = W ;j>= w[i] ; j--)
         dp[j] =std:: max(dp[j] , dp[j-w[i]] + v[i]) ;
      std::cout<<dp[W]<<'\n' ;   

}
int main()
{
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    solve() ;

}