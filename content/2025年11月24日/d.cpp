#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
const int mod = 1e9+7;

int a[N];
PII ans[N];
int it;
int jie[N];
void init()
{
    jie[0]=1;
    for(int i=0;i<N;i++)a[i]=i;
    for(int i=1;i<N;i++)
    {
        jie[i]= i*jie[i-1];
        //  cout<<jie[i]<<'\n';
        jie[i]%=mod;
    }
    // cout<<jie[1]<<'\n';
}
int po(int a,int b)
{
     int res =1;
     while(b)
     {
         if(b&1)res = res *a % mod;
         b>>=1;
         a=a*a%mod;
     }
     return res;
}
int C(int a,int b)
{ 
    if(a==0)return 1;
    //  cout<<"jia jia-b "<<a<<' '<<b<<' '<<jie[a]<<' '<<jie[a-b]<<'\n';
     return jie[a]%mod * (po(jie[a-b]*jie[b]%mod,mod-2))%mod;
}
int n,x,pos;
int xiao =0 ,da=0;
void bs(int x)
{
    int l=0,r=n;
    while(l<r)
    {
         int mid = (l+r)>>1;
         if(a[mid]==pos)
         {
            l=mid+1;
         }
         else if(a[mid]<pos)
         {
            l=mid+1;
            xiao++;
         }
         else
         {
             r=mid;
             da++;
         }
        //  cout<<l<<' '<<r<<'\n';
    }
}
int A(int a,int b)
{
    if(a==0)return 1;
    // cout<<"jia jia-b "<<a<<' '<<b<<' '<<jie[a]<<' '<<jie[a-b]<<'\n';
     return jie[a]%mod*po(jie[a-b],mod-2)%mod;
}
void solve()
{

  cin>>n>>x>>pos;
  xiao=0;
  da=0;
  bs(pos);
  da--;
  cout<<da<<' '<<xiao<<'\n';
  int ans =1 ;
  if(n-x < da)
  {
    cout<<0<<'\n';
    return;
  }
  if(x-1< xiao)
  {
    cout<<0<<'\n';
    return;
  }
  int da1 = n-x;
  int xiao1 = x-1;

//   cout<<ans<<'\n';
//    cout<<C(da1,da)<<'\n';
//    cout<<A(da,da)<<'\n';
  ans *= C(da1,da)*A(da,da)%mod;
  ans%=mod;
//   cout<<ans<<'\n';
  ans*=C(xiao1,xiao)*A(xiao,xiao)%mod;
//    cout<<ans<<'\n';
  ans%=mod;
  int shen =  n -xiao -da -1;
  ans *= jie[shen];
//    cout<<ans<<'\n';
  ans%=mod;
  cout<<ans<<'\n';
  

   

}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    init();
    // cin>>t;

    // while(t--)
    solve();
}