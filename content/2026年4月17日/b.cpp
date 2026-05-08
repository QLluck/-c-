#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 1e5 + 7;
map<PII, int> mp;
vector<int> t[N];
int d[N];
int f[N];
int lowbit(int x) { return x & -x; }
void solve()
{
    int n;
    cin >> n;
    int sum = 1;
    int k = 0;
    int ans = 0;
    for (int i = 2; i <= 32;i++)
    {
        k++;
        sum *= 2;
        int l =(n + 1) / (sum * 2);
        int r = (n) / (sum);
        int a1 = (n - sum * r + 1);
        int num = r - l ;
        int an = (a1 + sum * (num - 1));
        int t1 = k * (a1 + an) * num / 2;
        int t2 = sum * (1 + l) * l / 2;
        ans += k * (a1 + an) * num / 2;
        ans += k*sum * (1 + l) * l / 2;
        // cout << t1 << ' ' << t2 << ' ' << sum << '\n';
    }
    cout << ans << '\n';
}


signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}