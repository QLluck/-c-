#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 7;
int me[N + 10] = {0};
int prime[N + 10] = {0}, it;
int p1[N];
int a[N];
void init()
{
    me[0] = 1;
    me[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!me[i])
            prime[++it] = i;

        for (int j = 0; j < it; j++)
        {
            if (i * prime[j] >= N)
                break;
            me[i * prime[j]] = 1;

            if (i % prime[j] == 0)
                break;
        }
    }
    // cout<<"yes"<<'\n';
    // for (int i = 0; i < it;i++)
    //     p1[i + 1] = p1[i] + prime[i];
    // cout << "yes" << '\n';
}
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (sum >= p1[n - i + 1])
        {
            cout << i - 1 << '\n';
            return;
        }
        sum -= a[i];
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    init();
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}
// 2 2 2 4 11
// 18
// 2 3 5 7 9
// 2 2 4 11
//
// 0 1 4
// 2 3 5
// 6 7 8