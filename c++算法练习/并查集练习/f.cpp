#include<iostream>
#include<map>
#include<algorithm>
using namespace std ;
#define ll long long 

const int N =2e5+7 ;
int n,m ; 
int mez[N] = {0} ;
int mef[N]={0} ;
int sum[N]={0} ;
void solve()
{
      scanf("%d %d",&n,&m) ;
      for(int i = 1 ; i<=n ;i++)
      {
          mez[i] = n ;
          mef[i] = 1 ;
      }
      while(m--)
      {
          int l,r ;
        ll s ;
          scanf("%d %d %lld",&l,&r,&s) ;
        if(add(l,r) <s) 
        {
            continue ;
        }
        else 
        {
              
        }

          

      }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}