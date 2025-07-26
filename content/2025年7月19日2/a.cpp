#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
struct node
{
    int x, y;
   int  d;
};
vector<node> a[6];
bool cmp(node a,node b)
{
    return a.d < b.d;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 4;i++)
        a[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            node temp;
            temp.x = x;
            temp.y = y;
            temp.d = x * x + y * y;
            if (x >= 0 && y >= 0)
                a[1].push_back(temp);
            if (x < 0 && y > 0)
                a[2].push_back(temp);
            if (x < 0 && y < 0)
                a[3].push_back(temp);
            if (x > 0 && y < 0)
                a[4].push_back(temp);
        }
    sort(a[1].begin(), a[1].end(), cmp);
    sort(a[2].begin(), a[2].end(), cmp);
    sort(a[3].begin(), a[3].end(), cmp);
    sort(a[4].begin(), a[4].end(), cmp);
    int i1 = 0, e1 = a[1].size() - 1;
    int i2 = 0, e1 = a[2].size() - 1;
    int i3 = 0, e1 = a[3].size() - 1;
    int i4 = 0, e1 = a[4].size() - 1;
    int ans = 0;
    for (int i = i1; i <=e1;i++)
    {   
       if()
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}