// 顺序表
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i <= n;i++)
    {
        sum |= i;
        cout << i << ' ' << sum << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}