#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
char ans[107][107];
int n, k, no;

void bfs()
{
    queue<PII> que;
    map<PII, int> me;
    me[{1, 2}] = 1;
    me[{1, 1}] = 1;
    if (no != 0)
    {
        ans[1][1] = 'R';
        ans[1][2] = 'L';
    }
    else
    {
        ans[1][1] = 'D';
        ans[1][2] = 'D';
    }
    que.push({1, 1});
    que.push({1, 2});
    int num = 2;
    while (que.size())
    {
        int x = que.front().fi, y = que.front().se;
        que.pop();
        for (int i = 0; i <= 1; i++)
        {
            int x1, y1;
            if (i == 0)
                x1 = x + 1, y1 = y;
            else
                x1 = x, y1 = y + 1;
            if (me[{x1, y1}] || x1 < 1 || x1 > n || y1 < 1 || y1 > n)
                continue;
            num++;
            me[{x1, y1}] = 1;
            if (num <= no)
            {

                if (i == 0)
                    ans[x1][y1] = 'U', que.push({x1, y1});
                else
                    ans[x1][y1] = 'L', que.push({x1, y1});
            }
            else
                ans[x1][y1] = 'D', que.push({x1, y1});
        }
    }
}
void solve()
{
    cin >> n >> k;
    no = n * n - k;
    if(n==1)
    {
        if(k==1)
        {
            cout << "YES" << '\n';
            cout << 'U' << '\n';
        }
        else
            cout << "NO" << '\n';
        return;
    }
    if (no == 1)
    {
        cout << "NO" << '\n';
        return;
    }
    bfs();
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}
// 0 1 2 3 4 5 6 7
// 0 1 2 3 0 1 2 3

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}