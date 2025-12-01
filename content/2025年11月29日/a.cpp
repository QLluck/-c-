#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
const int mod = 1e9+7;
int a[N];
int po(int a,int b)
{
    int res =1;
    while(b)
    {
        if(b&1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void solve()
{
    
   int p,q,r;
   cin>>p>>q>>r;
   int n;

   int chu = po(1000,mod-2)%mod;
   int pr = r*chu%mod;
   int prf = (1-pr +mod) %mod ;
   int pp = p*chu%mod;
   int ppf = (1-pp+mod)%mod;
   int pq = q*chu%mod;
   int pqf = (1-pq+mod)%mod;
   int p0f = 0;
   int p0s = 1;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   int sum =0 ;
   int p00=1,p10=0,p20=0;
   int f = 1;
   for(int i=1;i<=n;i++)
   {
    int p01=0,p11=0,p21=0;
        if(sum+a[i]>=81 && f)
        {

            int l = 81-sum-1 ;
            int r = sum+a[i]-81+1;
            int pb = (pp + ppf *pq %mod )%mod;
            int pbf = (1-pb+mod)%mod;
            p01 = po(ppf,l) * po(pbf,r)%mod;
            if(l>=1)
            p11 = l%mod*po(ppf,l-1) %mod * pp %mod *po(pbf,r)%mod;
            else p11=0;
            if(r>=1)
            p11 = (p11 + r %mod * po(pbf,r-1)*pb %mod *po(ppf,l)%mod)%mod ;

            if(l>=2)
            p21 = l%mod*(l-1)%mod*po(ppf,l-2)%mod *po(pp,2)%mod*po(pbf,r)%mod;
            else p21=0;
            if(r>=2)

            p21 = (p21+ r%mod*(r-1)%mod*po(pbf,r-2)%mod *po(pb,2)%mod *po(ppf,l)%mod )%mod;
            if(r>=1 && l>=1)

            p21 = (p21+ r%mod*l%mod*po(pbf,r-1)%mod *po(pb,1)%mod *po(ppf,l-1)%mod*po(pp,1)%mod )%mod;

            pp = pb ;
            ppf = pbf;
            f=0;
        }
        else 
        {
            p01=po(ppf,a[i])%mod;
            if(a[i]>=1)
            p11 = a[i] * po(ppf,a[i]-1)%mod * pp%mod;
            if(a[i]>=2)
            p21 = (1-p11+mod - p01 +mod)%mod;

        }
        int p0 = (p00*p01)%mod ;
        int p1 = (p00*p11%mod) + (p10*p01 %mod *prf %mod )%mod;
        int p2 = ((p00*p21)%mod +(p10*pr)%mod + (p10*prf%mod*p11%mod )%mod)%mod;
        // p0s = (p0s)%mod*p2%mod;
        // p0f = (1-p0s+mod)%mod;
        p00=p0*(1-p20+mod)%mod;
        p10=p1 *(1-p20+mod)%mod;
        p20=p2*(1-p20+mod)%mod;
        sum+=a[i];
        // sum%=mod;
        cout<<p20<<'\n';
   }


}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // pri();
    // cout<<prime[3125000]<<'\n';
    // cout<<it<<'\n';
    solve();
    // te();
}
//0 8 10 8 10 0 8 9 10 2 0 6 0 7 4 1 5 3 6 5