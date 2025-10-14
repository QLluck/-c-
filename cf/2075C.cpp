#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
int a[N];
int tn[N];
int ts[N];
int lowbit(int x){return x&-x;}
int n,m;
void add(int x,int k,int t[])
{
    while(x<=n)
    {
        t[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x,int t[])
{
    int res=0;
    while(x)
    {
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void solve()
{
   // int n,m;
    cin>>n>>m;
    int ans =0 ;
   // for(int i=1;i<=n;i++)ts[i]=0,tn[i]=0;
    for(int i=1;i<=m;i++)
    {
        
        cin>>a[i];

    }
    sort(a + 1, a + m + 1);
    // for (int i = 1; i <= m;i++)
    //     cout << a[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n-1; i++)
    {
        int x = m - (lower_bound(a + 1, a + m + 1, i) - a)+1;

        int y = m - (lower_bound(a + 1, a + m + 1, n - i) - a)+1;

       // cout << x << ' ' << y << '\n';
        ans += x * y - min(x, y);
    }

        cout << ans << '\n';
        
}
//134
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
