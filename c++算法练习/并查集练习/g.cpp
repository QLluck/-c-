#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std ;
#define ll long long 

const int N =1e4+7 ;
int n,m ,w; 
int a[N]={0} ;
int v[N]={0} ;
int me[N]={0} ;
 int dp1[N]={0} ;
 int dp2[N]={0} ;
int find(int x)
{
     if(me[x]==x) return x  ;
     return me[x] = find(me[x]) ;
}
void solve()
{
  cin>>n>>m>>w ;
  for(int i = 1 ; i<=n ;i++)
  {
     cin>>a[i]>>v[i] ;
     me[i] = i ;
  }

  while(m--)
  {  int x,y ;
  cin>>x>>y ;
    if(find(x)==find(y))continue ;
       int d =a[find(x)] +a[find(y)] ;
      int sum = v[find(x)]+v[find(y)] ;
      me[find(x)] =find(y) ;
      v[find(y)] = sum ;
      a[find(y)] = d ;

  }
 map<int,int> mp ;
vector<int> arr; 
  for(int i =  1 ; i<=n ;i++)
  {
     if(mp.count(find(i))) continue ;
     mp[find(i)] =1 ;
    arr.push_back(find(i)) ;
  }



  for(int i = 1 ;i<=arr.size() ;i++)
  {
      for(int j = 1 ; j<= w ;j++)
      {  dp2[j] = dp1[j] ;
          if(a[arr[i-1]]<=j)
          {
             dp2[j] = max(  dp2[j], dp1[j-a[arr[i-1]]  ]  + v[ arr[i-1]] );
          }
      }
      for(int j = 1 ;j <=w ;j++) dp1[j] = dp2[j] ;
  }
  cout<<dp2[w]<<endl ;

   



}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}