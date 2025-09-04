#include<bits/stdc++.h>
using namespace std;
#define int long long
int po(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res = res*a%9;
        b>>=1;
        a=a*a%9;
    }
    return res;
}
void solve()
{
    int l,r;
    cin>>l>>r;
    int ans = r-l+1;
    ans = ans%9*(l+r)%9 *5%9;
    ans = ans%9;

    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    solve();
}