#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];

int l[N];
int r[N];
int ans[N];
deque<int> sta;
void solve()
{
    int n;
    cin >> n;
    
    int it = 0;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> l[i] >> r[i];
    int rl = 0;
    int ll = 0;
    for (int i = 1; i <= n;i++)
    {
        if(a[i]==-1)
        {
            rl++;
            sta.push_back(i);
        }
        if(a[i]==1)
            rl++, ll++;
    
        while(ll<l[i])
        {
            if (sta.size() == 0)
            {
                cout << -1 << '\n';
                return;
            }
            a[sta.back()] = 1;
            ll++;
            sta.pop_back();
        }
        while ( rl > r[i])
        {  if(sta.size()==0)
            {
                cout << -1 << '\n';
                return;
            }
            a[sta.back()] = 0;
            rl--;
            sta.pop_back();
        }

    }
    while(sta.size())
    {
        a[sta.back()] = 0;
        sta.pop_back();
    }
    for (int i = 1; i <= n;i++)
    {
            cout << a[i] << ' ';

    }
    cout << '\n';

    // 0 1 2 3 4
    // 0 0 0 1 1

}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}