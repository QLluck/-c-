#include<bits/stdc++.h>
using namespace std;
#define int long long 
const double mi =1e-9; 
const int N = 1e6+7;
const int mod = 1e9+7;
int a1[N];
int a2[N];
int a3[N];
int s3[N];
int n,a[N];
int po(int a,int b)
{
    int res= 1;
    while(b)
    {
        if(b&1)res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
void te()
{   a1[0]=0;
    a2[0]=0;
    a3[0]=0;
    // a4[0]=0;
    a[0]=0;

    for(int i=1;i<=n;i++)
    { a1[i]=a1[i-1]+a[i];
        a1[i]%=mod;
        a2[i]=a2[i-1] + ((a[i]*a[i])%mod);
        a2[i]%=mod ;
        a3[i]=a3[i-1]+(((a[i]*a[i])%mod*a[i])%mod );
        a3[i]%=mod;

        s3[i]= ((((a1[i]*a1[i]%mod)*a1[i])%mod )- ((3*a2[i]%mod)*a1[i]%mod)%mod + (2*a3[i])%mod  + mod)%mod ;
        // cout<<s3[i]<<'\n';
    }

}
void solve()
{
//    cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
//    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//    cout<<'\n';
      te();
    int ans =0 ;
    for(int i= 4; i<=n;i++)
    {
        ans += (s3[i-1] *i)%mod;
        ans%=mod;
    }
    ans*=po(6,mod-2);
    ans%=mod;
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    int a,b,c;

    while(cin>>n)
    solve();
}