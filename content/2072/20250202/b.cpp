#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
ll arr[N]={0};
void solve()
{
   ll x,y,z,k;
   cin>>x>>y>>z>>k; 
   ll sum = 0 ;
   for(ll i = 1 ;i<=x; i++)
   {       if(i>k)continue ;
      for(ll j =1; j<=y ;j++)
      { double  g1 = (double)k/(i*j) ;
         ll g = g1 ;
          if(   g == g1   )
          {
             
                 ll num = (x -i+1 )* (y -j+1 )* (z -g+1 ) ;
                 sum =max(sum,num);
          }
              
        
      }
   }
   cout<<sum<<'\n';
  


   


}
int main()
{
      ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
      int t;
      cin>>t ;
      while(t--)
      solve();
}