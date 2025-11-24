#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int a[N];
void solve()
{
    int qian = 0;
    int n;
    cin >> n;
    qian = 1;
    int ans = 0;
    int sum = 0;
    int num = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int it = 2;
    while (it <= n)
    {

        while (it <= n && sum < qian)
        {
            while (it <= n - 1 && a[it] < a[it + 1])
                num++, it++;
            num++;
            it++;
            sum++;
        }
        qian = num;
        num = 0;
        sum = 0;
        ans++;
    }

    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}