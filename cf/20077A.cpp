#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5+7;
int a[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n*2;i++)cin>>a[i];
    sort(a+1,a+n*2+1);
    int fu = 0;
    for(int i=1;i<=2*n-2;i+=2)fu+=a[i]-a[i+1];
    int ans=  a[2*n]+a[2*n-1]-fu;
    cout<<a[2*n]<<' ';
    for(int i=1;i<=2*n;i++)
    {
       
         if(i==2*n-1)cout<<ans<<' ';
        else if(i==2*n)cout<<a[2*n-1]<<' ';
        else cout<<a[i]<<' ';
    }
    cout<<'\n';
    // 1 4 6 8
    // x-6-3=8
    //
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
