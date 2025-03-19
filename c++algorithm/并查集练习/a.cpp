#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5+7 ;
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
      for(int i= 1 ; i<= n; i++)
      {  cin>>arr[i] ;
          me[i] = i ;
          v[i] = 0 ;
          
      }


  ll ans = 0 ;
      for(int i = 0 ; i<m ;i++)
      {
          int x,y ;
          cin>>x>>y ;
        int mi = min(arr[find(x)],arr[find(y)] ) ;
        me[find(x)] = find(y) ;
        arr[find(y)] = mi ;
      }
      map<int,int> mp ;
      for(int i = 1 ; i<=n ;i++)
      {  if(mp.count(find(i)))continue ;
         ans+= arr[find(i)] ;
         
         mp[find(i)] =  1; 
      }
      cout<<ans<<endl ;
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}