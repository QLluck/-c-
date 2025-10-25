#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
int a[N];
int b[N];
int me[N];
pii c[N];
void solve()
{
   
int n,m;
cin>>n>>m;

   int ans = n ;
   for(int i=2;i<=m;i++)
   {
       int num = i*i-i;
       while(num<=n)
       {
           ans++;
           num+=i*i;
       }
   }
   cout<<ans<<'\n';
   
    


}

void te()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
             if( ((i+j)%(j*gcd(i,j))==0 )&&j==k )cout<<i<<' '<<j<<' '<<(i+j)<<' '<<gcd(i,j)<<'\n';
        }
    }
}
// gcd(a,b) * a1 + gcd(a,b)*b1 ;  (a1 + b1 )/gcd(a,b)*b1 ;  a1 / gcd(a,b)*b1   + b1/gcd(a,b);
//
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    // te();
}