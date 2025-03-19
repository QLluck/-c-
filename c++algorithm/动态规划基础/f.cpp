#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N = 1e3+7 ;
ll dp[N]={0} ;
int me[N] ={0} ;
int prime[N] ,it ;

void pri()
{
      for(int i= 2; i <=N ;i++)
      {
           if(!me[i]) 
                prime[it++] = i ; 
           for(int j = 0 ; j< it ;j++)
           {
                if(i*prime[j]>=N) break ;
                me[i*prime[j]]=1 ;
                if(i%prime[j]==0) break ;
           }
          
      }
}
void solve()
{ pri() ;
     int n;
     cin>>n ;

     dp[0]=1 ;
for(int i = 2 ; i<=n ;i++)
   if(!me[i])
     for(int j = i ; j<=n ;j++)
       dp[j]+=dp[j-i] ;

     cout<<dp[n]<<'\n' ; 
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}