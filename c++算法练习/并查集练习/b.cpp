#include<bits/stdc++.h>
using namespace std ;
const int N = 1e2+7 ;
#define ll long long
int n,m ;
int me[N]={0} ;
int v[N] ={0} ;
int arr[N]={0} ;
int find(int x)
{
     if(me[x]==x) return x ;
     return me[x] = find(me[x]) ;
}
void solve()
{
     cin>>n>>m ;
     for(int i = 0  ;i<=n ;i++)
     {
          me[i] = i ;
     }
          int ans=  0 ;
     for(int i = 1 ; i<=n ; i ++)
     {
          int k ;
          cin>>k ;
          int la ;
          if(k==0) ans++; 
          for(int i = 1 ; i<=k ;i++)
          {   int a ;
             cin>>a ;
               if(i==1)  
                {   
                    la =a ;
                     v[a] = 1 ;
                    continue ;
                }
                me[find(la)] = find(a) ;

              v[a] = 1 ;
          }
     }

     for(int i = 1 ; i<=m ; i++)
     { if(!v[i]) continue ;
          for(int j =i+1 ; j<=m ;j++)
          {
              if(!v[j]) continue ;
              if( find(i)!=find(j))
              {
                  me[find(i)] = find(j) ;
                  ans++; 
              }
          }

     }
     cout<<ans<<endl ;
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}