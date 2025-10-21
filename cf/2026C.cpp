#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N]={0};
deque<int> n1;
deque<int> n0;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    n1.clear();
    n0.clear();
    for (int i = 1; i <= n;i++)
    {
        a[i] = (s[i - 1] - '0');

        if(a[i])
            n1.push_back(i);
        else
            n0.push_back(i);
    }

    int ans = (n + 1) * n / 2;
    while(n1.size())
    {
        int it = n1.back();
        n1.pop_back();
        while(n0.size()&&n0.back()>=it)
            n0.pop_back();
        if(n0.size())
        {
            n0.pop_back();
            ans -= it;
        }
        else if(n1.size())
        {
            n1.pop_front();
            ans -= it;
        }
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
