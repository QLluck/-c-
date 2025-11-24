#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int n1 = 0, n0 = 0;
    for (int i = 0; i < n-1;i++)
    {
        if(s[i]=='1'&&s[i+1]=='1')
            n1++;
        if(s[i]=='0'&&s[i+1]=='0')
            n0++;
    }
    cout << max(n1, n0) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}