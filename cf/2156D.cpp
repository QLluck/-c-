#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
mt19937_64 rng(random_device{}());
int a[N];
int ans[N];
int sum[N];
map<int, int> mp;
map<int, int> me[N];
int rad(int x)
{
    int res = 0;
    while (res == 0)
    {

        int n = sum[x];
        int yu = rng() % n;
        if (yu == 0)
            yu = n;
        int num = a[yu];
        // cout<<x<<' ' << num << ' ' << yu << ' ' << n << '\n' ;
        if (mp[num] || me[x][num])
        {
            res = 0;
            swap(a[yu], a[n]);
        }
        else
        {
            res = num;
            me[x][num] = 1;
            swap(a[yu], a[n]);
        }
        sum[x]--;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++)
        a[i] = i, me[i].clear(), ans[i] = 0, sum[i] =n;

    for (int i = 1; i <= n - 1; i++)
    {
        int flag = 1;
        int x = 0;
        while (flag)
        {
            if (sum[i] == 1)
            {
                x = rad(i);
                flag = 1;
                break;
            }
            x = rad(i);
            // cout << sum[i] << ' ' << '\n';
            int y = ((1LL<<32) -1 )
            cout << "? "<<i<<' '<< x << '\n';
            cout.flush();
            cin >> flag;
            flag = !flag;
            cout.flush();
        }
        ans[x] = 1;
        mp[x] = 1;
    }
    for (int i = 1; i <= n;i++)
    {
        if(ans[i]==0)
        {
            cout << "! " << i << '\n';
            return;
        }
    }
}
void init()
{
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    // init();
    while (t--)
        solve();
}