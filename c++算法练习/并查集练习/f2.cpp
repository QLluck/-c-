#include<bits/stdc++.h>
int n,k ;
const int N =2e5+7 ;
#define ll long long
int me[N]={0} ;
ll sum[N]={0} ;
int l[N]={0} ;
int r[N]={0} ;
int s[N]={0} ;
int find(int x)
{
      if(me[x]==x) return x;
       int fu = find(x) ;
        me[fu] = find(fu) ;
      return  fu ;
}

void solve()
{
     std::cin>>n>>k ;
     int ans =0 ;
     for(int i = 0 ; i<= n; i++) me[i] = i ;
      for(int i =  1 ; i<= k ;i++) 
     {
          std::cin>>l[i]>>r[i]>>s[i] ;
     }

     for(int i =2 ; i<=k ;i++)
     {
          me[find(l[i-1])] = find(r[i-1]) ; 
          sum[l[i-1]] = s[i-1] ;
          if(r[i-1] >=r[i])
          {
              
          }
          else 
          {
             
          }

     }

}
int main()
    {
         std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0) ;
         solve() ;


    }