#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
int a[N] = {0};
int b[N]={0};
int pri[N] = {0};
int bac[N] = {0};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    int ita = 1;
    int itb = 1;
    for (; itb <= m;itb++)
    {
        while(ita<=n&&a[ita]<b[itb])
            ita++;
        pri[itb] = ita;
        ita++;
    }

        ita = n, itb = m;
        for (; itb >= 1; itb--)
        {
            while (ita >= 1 && a[ita] < b[itb])
                ita--;
            bac[itb] = ita;
            ita--;
        }
    // for (int i = 1; i <= m;i++)
    //     cout << bac[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= m;i++)
    //     cout << pri[i] << ' ';
    // cout << '\n';
    int mi = 1e9 + 7;
    if(bac[1]>=1||pri[m]<=n)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= m;i++)
    {
        int n1 = (i == 1) ? 0 : pri[i - 1];
        int n2 = (i+1 == m+1) ?  n+1 : bac[i + 1];
       // cout << n2 << ' ' << n1 << '\n';
        if(n1<n2)
           { mi = min(mi, b[i]);
               //cout << b[i] << '\n';
           }
    }
    cout << (mi==INF?-1:mi) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}