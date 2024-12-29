#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N = 1e3+7 ;
ll dp[N]={0} ;
int me[N] ={0} ;
int prime[N] ,it ;

void pri(int n )
{
      for(int i= 2; i <=n ;i++)
      {
           if(!me[i]) 
             {  prime[it++] = i ;
          

             }
           for(int j = 0 ; j< it ;j++)
           {
                if(i*prime[j]>n) break ;
                me[i*prime[j]]=1 ;
                if(i%prime[j]==0) break ;
           }
            if(!me[i]) 
             {  
                dp[i]++ ;
               for(int j = 0 ; j <it;j++)
               {
                    if(i+prime[j]>n) break ;  
                  dp[  i+ prime[j] ] += dp[i] * dp[prime[j]] ;
               //    cout<<dp[j]<<' ' ;
               }
               // cout<<'\n' ;

             }
      }
}
void solve()
{
     int n;
     cin>>n ;
     pri( n) ;
     for(int i = 0; i <=n ;i++)
     {
          cout<<dp[i]<<' ' ;
     }
     cout<<'\n' ;
     cout<<dp[n]<<'\n' ; 
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}