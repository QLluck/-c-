#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
#define pii pair<int,int >
#define fi first 
#define se second
#define int long long
pii a[N];
int f(int x)
{
     int res= 0 ;
     while(x>1)
     {
        if(x&1)x= x/2 +1;
        else x>>=1;
        res++;
     }
     return res;
}
void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans= 0 ;
    // int nz = (n&1)? (n/2+1==a) : (n/2==a);
    // int mz = (m&1)? (m/2+1==b) : (m/2==b);
    if(n==1&&m==1)ans =0;
    else 
    {
    int a1 = f(n-a+1)+f(m)+1;
    int a2 = f(a)+f(m)+1;
    int a3 = f(n) +f(m-b+1)+1;
    int a4  = f(n)+f(b)+1;
    ans =min(a1,a2);
    ans =min(a3,ans);
    ans =min(a4,ans);
    }
cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}