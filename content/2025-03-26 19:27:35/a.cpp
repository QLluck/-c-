#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =1e7+7 ;


int prime[N],it ;
int me[N]={0};
void pri()
{
      me[1]=1;
      me[0]=1;
      for(int i =1; i<N ;i++)
      {
          if(!me[i])prime[it++]=i;
          for(int j = 0; j <it ;j++)
          {
              if(i*prime[j]>=N)break;
              me[i*prime[j]]=1;
              if(i%prime[j]==0)break;
          }
      }
   
}

void solve()
{ 
    ll n ;
    cin>>n;
   
   ll ans= 0 ; 
    int i =0 ;
    while(prime[i]<=n&&i<it)
    {
          ans+=n/prime[i];
          i++;
    } 
   
   
   cout<<ans<<'\n';
    
   

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     pri();
   
     cin>>t ;
     while(t--)
     solve();
}