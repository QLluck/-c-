#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e5+7;
int a[N];
pii b[N];
int me[N];
void solve()
{ 
 int n,k;
 cin>>n>>k;
 for(int i=1;i<=n;i++)cin>>a[i];
 if(k==1)
 {
    int ans =0 ;
    for(int i=1;i<=n;i++)
    {
        if(i==1||i==n)ans =max(ans,a[1]+a[n]);
        else 
        {
            ans = max(ans,a[i]+a[1]);
            ans = max(ans,a[i]+a[n]);
        }


    }
    cout<<ans<<'\n';
    return;

 }
 int ma= 0;
 sort(a+1,a+1+n);
 for(int i = n;i>=n-k;i--)ma+=a[i];
 cout<<ma<<'\n';




}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}
//4 3 3  2 1 
//4 2 3 1 3