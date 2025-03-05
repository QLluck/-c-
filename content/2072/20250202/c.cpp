#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
ll arr[N]={0};
void solve()
{
   int n,k;
    cin>>n>>k; 
    if(k>=n&&n!=1)
    {
         cout<<-1<<'\n';
         return ;
    }
    if(n==1)
    {  if(k==1)
    {
          cout<<1<<'\n';
          cout<<1<<'\n';
          return ;
    }
    else 
     {  cout<<-1<<'\n';
     return ;
     }
    
    }
     if(k==1)
     {
          cout<<-1<<'\n';
          return ;
     }
    cout<<3<<'\n';
    if( (n/2 )&1 )
    {
          if(k== (n/2 +1) )
          {  
             cout<<1<<' '<<k<<' '<<k+1<<'\n';
          }
          else if(k<(n/2+1))
          {  if(k&1) 
             cout<<1<<' '<<k-1<<' '<<k+2<<'\n';
             else    cout<<1<<' '<<k<<' '<<k+1<<'\n';
          }
          else if(k>(n/2+1))
          {
              if(k&1)
                cout<<1<<' '<<k-1<<' '<<k+2<<'\n';
                else  cout<<1<<' '<<k<<' '<<k+1<<'\n';
          }
    }
    else  
    {
          if(k== (n/2 +1) )
          {  
             cout<<1<<' '<<k-1<<' '<<k+2<<'\n';
          }
          else if(k<(n/2+1))
          {  if(k&1) 
             cout<<1<<' '<<k-1<<' '<<k+2<<'\n';
             else    cout<<1<<' '<<k<<' '<<k+1<<'\n';
          }
          else if(k>(n/2+1))
          {
              if(k&1)
                cout<<1<<' '<<k-1<<' '<<k+2<<'\n';
                else  cout<<1<<' '<<k<<' '<<k+1<<'\n';
          }
    }
   

   


}
int main()
{
      ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
      int t;
      cin>>t ;
      while(t--)
      solve();
}