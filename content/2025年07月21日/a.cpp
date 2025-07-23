#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;

    if(a>b+1)
    {
        cout<<-1<<'\n';
        return;
    }
    

    if(a==b+1)
    {    // ans = min(x,y);
         if(a&1)cout<<y<<'\n';
         else cout<<-1<<'\n';
         return;
    }
    else if(a==b)
    {
        cout<<0<<'\n';
        return;
    }
    int ans =0 ;
    if(a&1)ans+=x,a+=1;
    if(a==b)
    {
        cout<<ans<<'\n';
        return;
    }
    if(b&1)ans+=min(x,y),b-=1;
    int sub = b-a;
    ans += sub/2 *x + sub/2*min(x,y);
    cout<<ans<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}