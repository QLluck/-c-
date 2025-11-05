#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N] = {0};
deque<int> n1;
deque<int> n0;

void solve()
{
    int n;
    n1.clear();
    n0.clear();
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int a;
        cin >> a;
        if(a&1)
            n1.push_back(a);
            else
            n0.push_back(a);
    }
    while((n1.size() + n0.size()) >=2 )
    {
        int a, b;
        if(n1.size())
        {
            a = n1.back();
            n1.pop_back();
        }
        else 
        {
            a = n0.back();
            n0.pop_back();
        }
        if(n1.size())
        {
            b = n1.back();
            n1.pop_back();
        }
        else 
        {
            b = n0.back();
            n0.pop_back();
        }
        int tmp = (a + b) / 2;
        if(tmp&1)
        {
            n1.push_back(tmp);
        }
        else
            n0.push_back(tmp);
    }
    if(n1.size())
        cout << n1.front() << endl;
        else
            cout << n0.size() << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
