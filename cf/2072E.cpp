#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2007;
const int n1 = 500;
int a[N] = {0};
int p[n1 + 7];
pii ans[n1 + 7];
int it;
int f(int x);
void init()
{
    for (int i = 1; i <= n1; i++)
    {
        p[i] = f(i);
    }
}
int f(int x) { return (x) * (x - 1) / 2; }
void solve()
{
    it = 0;
    int k;
    cin >> k;
    int i = 1;
    // int it = 1;
    int j = 1;
    while (k)
    {
        int mi = lower_bound(p + 1, p + n1 + 1, k) - p;
        j = i;
        if (p[mi] == k)
        {
            for (int g = 1; g <= mi; g++)
            {
                ans[++it].fi = i;
                ans[it].se = ++j;
            }
            // k -= p[mi];
        }
        else
        {
            mi--;
            for (int g = 1; g <= mi; g++)
            {
                ans[++it].fi = i;
                ans[it].se = ++j;
            }
        }
        i += j;
        k -= p[mi];
        //  cout << k << ' ' << mi << ' ' << p[mi] << '\n';
    }
    cout << it << '\n';
    for (int i = 1; i <= it; i++)
        cout << ans[i].fi << ' ' << ans[i].se << '\n';
    // cout << it << '\n';
}
void test()
{
    // it = 0;
    // int k;
    for (int h = 1; h <= 1e5; h++)
    {
        int an = h;
        int k = h;
        it = 0;
        int i = 1;
        // int it = 1;
        int j = 1;
        while (k)
        {
            int mi = lower_bound(p + 1, p + n1 + 1, k) - p;
            j = i;
            if (p[mi] == k)
            {
                for (int g = 1; g <= mi; g++)
                {
                    ans[++it].fi = i;
                    ans[it].se = ++j;
                }
                // k -= p[mi];
            }
            else
            {
                mi--;
                for (int g = 1; g <= mi; g++)
                {
                    ans[++it].fi = i;
                    ans[it].se = ++j;
                }
            }
            i += j;
            k -= p[mi];
            // cout << k << ' ' << mi << ' ' << p[mi] << '\n';
        }
        // for (int i = 1; i <= it;i++)
        //     cout << ans[i].fi << ' ' << ans[i].se << '\n';
        // cout << it << '\n';
        // if(it>500)
        // {
        //     cout << an << '\n';
        // }
        // cout << ans[it].fi << ' ' <<ans[it].se << '\n';
    }
}
// 446
// 1 2
//
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    init();
    cin >> t;
    while (t--)

        solve();
    // test();

    // printb(2);
}
// 4 3 3  2 1
// 4 2 3 1 3