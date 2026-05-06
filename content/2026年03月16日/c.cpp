#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 1e6+7;
const int mod = 998244353;
int a[N];
int d[N];
int b[N]; 
int jie[N];
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
int C(int n,int m)
{
    int ans = jie[n];
    ans*=po(jie[n-m],mod-2);
    ans%=mod;
    ans*=po(jie[m],mod-2);
    ans%=mod;
    return ans;
}
int A(int n,int m)
{
     int ans = jie[n];
     ans*= po(jie[n-m],mod-2);
     ans%=mod;
     return ans;
}
int so(int n,int m,int num)
{
    if(n==1)return 1;
    else if(n==m)return 0;
    int s1 = po(m-1,num);
    // s1=po(s1,num);
    int s2 = po(m-n,num);
    // s2 = po(s2,num);
    int ans = s2 *po(s1,mod-2)%mod;
    return ans;
    

}
void solve()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
     cout<<so(i,m,n)<<' ';
  }
  cout<<'\n';
  


   
   
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