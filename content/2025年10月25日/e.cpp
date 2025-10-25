#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5+7;
int a[N];
int b[N];
int c[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    int ans = ((1+k)*k/2 ) * n;
    for(int i=0;i<=n+k;i++)b[i]=0,c[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;

    }
    int sum =0 ;
    for(int i=1;i<=k;i++)
    { 
        int num = i;
         int p,v;
         cin>>p>>v;
         
        ans += sum ;
        ans -= 
         a[p]=v;
 
         for(int j=1;j<=n;j++)
         {
            ans += (i-b[a[j]]);
            b[a[j]]++;
         }

    }
    cout<<ans<<'\n';


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
}