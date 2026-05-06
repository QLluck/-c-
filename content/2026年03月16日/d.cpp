#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 1e6+7;
const int mod = 998244353;
int a[N];
int p[N];
int fu[N];
int z[N];
int po(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
            res%=mod;
        }
        b>>=1;
    a*=a;
    a%=mod;
    }
    return res;
    
}
// int te()
// {
//     jie[0]=1;
//   for(int i=1;i<=N-2;i++)
//   {
//     jie[i]*=jie[i-1];
//     jie[i]%=mod;
//   }
// }
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 4 4 0 1 
//
void solve()
{
    int n;
    cin>>n;
    p[0]=0;
    fu[0]=0;
    int sum =0 ;
    int sz =0 ;
    int mi =1e9+7 ;
    int miit=0;
    for(int i=1;i<=n;i++)
    { cin>>a[i],p[i]=p[i-1]+a[i];
        if(a[i]<0)sum+=a[i];
        if(a[i]>=0)sz+=a[i];
        fu[i]=fu[i-1]+sum +sz ;
    //   if(  mi<fu[i]) mi= fu[i],miit=i;
        // z[i]=z[i-1]+sz;
    }
     if(p[n]<0)
    {
        cout<<-1<<'\n';
        return;
    }
    int ma = -1e9-7;
    int ans =0 ;
     sum=0;
    for(int i=1;i<=n;i++)
    {
        ma = max(ma,p[i]);
        if(fu[i]+sum<0)
        {
            if(ma<=0)
            {
                cout<<-1<<'\n';
                return;
            }
            ans += (abs(fu[i]+sum)+ma-1)/ma;
            sum+= ((abs(fu[i]+sum)+ma-1)/ma)*ma; 
        }
    }
    ans+=n;
    cout<<ans<<'\n';



    // for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    // cout<<'\n';
    // for(int i=1;i<=n;i++)cout<<fu[i]<<' ';
    // cout<<'\n';
    // for(int i=1;i<=n;i++)cout<<z[i]<<' ';
    // cout<<'\n';
   
    

   
   
}
//aaaaaa

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // te();
    t=1;
    while(t--)solve();
}