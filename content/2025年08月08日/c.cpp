#include<bits/stdc++.h> 

using namespace std;
#define int long long
const int mod = 1e9+7;
const int N  =5e5+7;
int a[N]={0};
int b[N]={0};
void solve()
{  
    int n;
    cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
   for(int i=1;i<=n;i++)cin>>b[i],b[i]=(b[i]+b[i-1])%mod;
   int ans =0 ;
   for(int i=0;i<=33;i++)
   {  int f0 =0,f1=0,s0=0,s1=0;
        for(int j=0;j<=n;j++)
        {
               if( (a[j]>>i )& 1 )
               {
                 ans =(ans+((f0*b[j]%mod-s0+mod)%mod)*((1LL<<i)%mod) )%mod;
                 f1++;
                 s1 = (s1 +b[j])%mod; 
               }
               else 
               {
                 ans =(ans+((f1*b[j]%mod-s1+mod)%mod)*((1LL<<i)%mod) )%mod;
                 f0++;
                 s0 = (s0 +b[j])%mod; 
               }
        }
   }
   cout<<ans<<'\n';
}
signed main( )
{ ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
int t;
//cin>>t;
t=1;
while(t--)
solve();
    return 0;
}
// (x+1)*a -1 = x *a + x*d a-1 = x*d;  x  = (a-1)/d ;x if(x>=1) sum =  mi-1 + ( (x+1) *mi -2*x +x*(x-1)*d/2     )