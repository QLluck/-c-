#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N] = {0};

void solve()
{
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;
    s = ' ' + s;
    int mait = 1, miit = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[mait])
            mait = i;
        if (a[i] < a[miit])
            miit = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && (i == mait || i == miit || i == 1 || i == n))
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << 5 << '\n';
    cout << 1 << ' ' << mait << '\n';
    cout << 1 << ' ' << miit << '\n';
    cout << miit << ' ' << n << '\n';
    cout << mait << ' ' << n << '\n';
    cout << min(miit, mait) << ' ' << max(miit, mait) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}