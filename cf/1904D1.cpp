#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int b[N];
PII a1[N];
int ita;
PII b1[N];
int itb;
int n, k;
void bfs(int num, int s)
{
    for(int i=s;i<=n;i++)
    {
        if(num > b[i])break;
        else if(num<a[i])break;
        else a[i]=num;
    }
    for(int i=s;i>=1;i--)
    {
        if(num > b[i])break;
        else if(num<a[i])break;
        else a[i]=num;
    }
}
void solve()
{
    
    cin >> n;
    ita =0;
    itb=0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    int l = -1;
    for (int i = 1; i <= n; i++)
    {
        if (l != b[i])
        {
            l = b[i];
            b1[++itb].fi = l;
            b1[itb].se =i;
        }
    }
    l = -1;
    for (int i = 1; i <= n; i++)
    {
        if (l != a[i])
        {
            l = a[i];
            a1[++ita].fi = l;
            a1[ita].se=i;
        }
    }
    int na =1,nb=1;
    sort(a1+1,a1+ita+1);
    for(int i=1;i<=ita;i++)
    {
         
     bfs(a1[i].fi,a1[i].se);

    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
    // for(int i=1;i<=ita;i++)cout<<a1[i]<<' ';
    // cout<<'\n';
    // for(int i=1;i<=itb;i++)cout<<b1[i]<<' ';
    // cout<<'\n';
    // while(na<=ita && nb<=itb )
    // {
    //     if(a1[na]==b1[nb])na++,nb++;
    //     else na++;
    // }
    // if(nb==itb+1)cout<<"YES"<<'\n';
    // else cout<<"NO"<<'\n';
}
// 0 1 2 3 4 5 6 7
// 0 1 2 3 0 1 2 3
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}