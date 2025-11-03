#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 3e5 + 7;
int check(int mid)
{
    cout << "? " << mid << ' ' << mid << endl;
    int a;
    cin >> a;

    if (a == (mid + 1) * (mid + 1))
        return 1;
    else
        return 0;
}
void solve()
{
    int l, r;
    l = 1, r = 1000;
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;

        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << "! " << r << endl;
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
