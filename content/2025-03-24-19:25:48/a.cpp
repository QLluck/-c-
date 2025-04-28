#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
int arr[N]={0};

void solve()
{
     double k,l1,r1,l2,r2;
     cin>>k>>l1>>r1>>l2>>r2;
    ll ans = 0 ; 
   


     while(r2>=l1)
     {
         
         if(l2<=r1&&r1>=l1)
         {
            ll mal =  ceil( max(l1,l2));
            ll mir = floor(min(r1,r2));
            if(mir>=mal) ans+= (mir - mal )+1;
         }
 
      

        r2/=k;
        l2/=k;


          
     }
     cout<<ans<<'\n';
     
   

     
    
    
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t ;
     cin>>t ;
     while(t--)
     solve();
}