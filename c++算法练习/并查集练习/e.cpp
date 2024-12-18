#include<iostream>
#include<map>
#include<algorithm>
const int N =1e3 +7 ;
using namespace std ;
int me[N] ={0} ;

int n,m ;
int find(int x)
{
      if(me[x]==x) return x ;
      return me[x] = find(me[x]) ;
}
void solve()
{
      cin>>n>>m ;
      for(int i = 1 ;i <=n ;i++) me[i] = i ;
      while(m--)
      {
          int x,y ;
          cin>>x>>y ;
          me[find(x)] = find(y);
      }
      map<int ,int > ans; 
      int sum = 0 ;
      for(int  i = 1 ;i<= n ;i++)
      {
          if(ans.count(find(i))) continue ;
          else 
          {
             ans[find(i)] =1 ;
             sum++;
          }
      }
      cout<<sum<<endl ;

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     cin>>t ;
     while(t--)
     solve() ;
}