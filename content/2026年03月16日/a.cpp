#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 2e6+7;
const int mod = 998244353;
int a[N];
int d[N];
int me[N];
int me2[N];

PII f[N];
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
void solve()
{
   int n,m;
   cin>>n>>m;
//    mp.clear();
//    map<int,int>mp;
//    for(int i=0;i<=60;i++)f[i].fi=0,f[i].se=0;
//    for(int i=1;i<=n;i++)d[i]=0,me[i]=0,me2[i]=0;
   for(int i=1;i<=N;i++)d[i]=0,me[i]=0,me2[i]=0;
   for(int i=1;i<=m;i++)
   {
    int u,v;
    cin>>u>>v;
    d[v]++,d[u]++;
   }
   sort(d+1,d+n+1);
   for(int i=1;i<=n;i++)me2[d[i]]++;
   int it = unique(d+1,d+n+1)-d-1;
   int ans=0;
   for(int i=1;i<=it;i++)
   {
   
     
        int sum =0 ;
      for(int j =1 ;j<=it;j++)
      {
        sum+= ((((d[i]^d[j])*(d[i]|d[j])%mod )*(d[i]&d[j])) %mod)*me2[d[j]]%mod;
        // sum%=mod;
        // sum*=me2[d[j]];
        
        sum%=mod;
      }
      ans+=sum*me2[d[i]]%mod;
      ans%=mod;
    //    me[d[i]]=sum;
    //    me[d[i]]%=mod;
    
   }
   ans=ans*po(2,mod-2);
   ans%=mod;
   cout<<ans<<'\n';

//    for(int j=1;j<=n;j++)
//    for(int i=33;i>=0;i--)
//    {
//         int yu = (d[j]>>i)&1;
//         if(yu)f[i].fi++;
//         else f[i].se++;
//    }
//    int ans2=0;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=33;j>=0;j--)
//        {
//          int yu = (d[i]>>j)&1;
//          int sum = (1LL<<j) ;
//          int s1=0,s2=0,s3=0;
//          if(yu)
//          {
//             s1=sum*f[j].se;
//             s2=sum*(f[j].fi+f[j].se);
//             s3=sum*f[j].fi;
//          }
//          else 
//          {
//             s1=sum*f[j].fi;
//             s2=sum*(f[j].fi);
//             // s3=sum*f[j].fi;
//          }
//          ans2+=s1*s2*s3;
//        }
//    }
//    cout<<ans2<<'\n';
//    for(int i=1;i<=n;i++)cout<<d[i]<<' ';
//    cout<<'\n';
// //    for(int i=1;i<=n;i++)cin>>a[i];
   
//    int ans=0;
//    for(int i=1;i<=n;i++)
//    {
//     for(int j=i;j<=n;j++)
//     { 
//         int x= 0 ;
//         x=(d[i]^d[j])*(d[i] | d[j])*( d[i]&d[j]);
//        ans+=x;
//         // cout<<x<<' '<<i<<' '<<j<<' '<<(d[i]^d[j])<<' '<<(d[i]|d[j])<<' '<<(d[i]&d[j])<<'\n';
//     }
//    }
//    cout<<ans<<'\n';
   
   
   
}
// 00000001111110000
// 101
// 001
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
}