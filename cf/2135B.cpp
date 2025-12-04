#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
const int IN = 100;
PII a[N];

void solve()
{
    int xmi = INF;
    int ymi = INF;
    int xma = -INF;
    int yma = -INF;
    int ld = INF;
    int rd = INF;
    int ru = INF;
    int xmiy, xmay, ymix, ymax;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].fi = x, a[i].se = y;
        int ldm = abs(x + IN) + abs(y + IN);
        if (ldm <= ld)
        {
            xmi = x;
            xmiy = y;
            ld = ldm;
        }
        int rdm = abs(x - IN) + abs(y + IN);
        if (rdm <= rd)
        {
            ymi = y;
            xma = x;
            xmay = y;
            ymix = x;
            rd = rdm;
        }
        int rum = abs(x - IN) + abs(y - IN);
        if (rum <= ru)
        {
            yma = y;
            ymax = x;
            ru = rum;
        }
    }
    // int xmi1 = INF;
    // int ymi1 = INF;
    // int xma1 = -INF;
    // int yma1 = -INF;
    // for (int i = 1; i <= n;i++)
    // {
    //     if(a[i].se==ymi)
    //     {
    //         xmi1 = min(xmi1, a[i].fi);
    //         xma1 = max(xma1, a[i].fi);
    //     }
    //     if (a[i].fi == xma)
    //     {
    //         yma1 = max(yma1, a[i].se);
    //         ymi1 = min(ymi1, a[i].se);
    //     }
    // }
    // xma = xma1;
    // xmi = xmi1;
    // ymi = ymi1;
    // yma = yma1;
    int tmp;
    cout << "? D " << IN << endl;
    cin >> tmp;
    cout << "? D " << IN << endl;
    cin >> tmp;
    cout << "? L " << IN << endl;
    cin >> tmp;
    cout << "? L " << IN << endl;
    int s1 = 0;
    cin >> s1;
    cout << "? R " << IN << endl;
    cin >> tmp;
    cout << "? R " << IN << endl;
    cin >> tmp;
    cout << "? R " << IN << endl;
    int s2;
    cin >> s2;
    int y1 = (s1 + s2 + xma - xmi - 3 * IN - (xmiy + IN) - (xmay + IN)) / 2;
    y1 = -IN - y1;

    cout << "? U " << IN << endl;
    cin >> tmp;
    cout << "? U " << IN << endl;
    cin >> tmp;
    cout << "? U " << IN << endl;
    cin >> s1;
    int x1 = (s1 + s2 + yma - ymi - 3 * IN - (IN - ymax) - (IN - ymix)) / 2;
    x1 = IN + x1;
    x1 = x1 - 3 * IN;
    x1 += 2 * IN;
    y1 += 2 * IN;
    cout << "! " << x1 << ' ' << y1 << '\n';
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
        solve();
}
