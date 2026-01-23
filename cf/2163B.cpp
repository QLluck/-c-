#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N] = {0};
int wei[N];
int st[N][20] = {0};
void init_st(int n)
{
    int len = log(n) / log(2) + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int i = 1; i < len; i++)
    {
        for (int j = 1; j <= n - (1 << i) + 1; j++)
        {
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            // cout<<j<<' '<<i<<' '<<st[j][i]<<'\n';
        }
    }
}
int query(int l, int r)
{
    int len = log(r - l + 1) / log(2);
    return max(st[l][len], st[r - (1 << len) + 1][len]);
}
string s;
int n;
vector<int> t[N];
int me[N];
int dma = 0;
PII d[N];
void build(int l, int r, int fa)
{
    // cout << l << ' ' << r << ' ' << fa << endl;
    int ls = 0, rs = 0;
    dma = max(d[fa].fi, dma);
    if (l == r)
        return;
    if (wei[fa] - 1 >= l)
        ls = query(l, wei[fa] - 1);
    if (wei[fa] + 1 <= r)
        rs = query(wei[fa] + 1, r);
    if (ls)
    {
        t[fa].push_back(ls);
        me[ls] = fa;
        d[ls].fi = d[fa].fi + 1;
        build(l, wei[fa] - 1, ls);
    }
    if (rs)
    {
        t[fa].push_back(rs);
        me[rs] = fa;
        d[rs].fi = d[fa].fi + 1;
        build(wei[fa] + 1, r, rs);
    }
}

int ans[N], it;
int find(int x)
{
    if (x == 0)
        return 0;
    if (s[wei[x] - 1] == '1')
    {
        s[wei[x] - 1] == '0';
        return find(me[x]) + 1;
    }
    else
        return find(me[x]);
}
void solve()
{

    cin >> n;
    int ma = 0;
    dma = 0;
    it = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], wei[a[i]] = i, t[i].clear(), me[i] = 0, ma = max(a[i], ma), d[i].fi = 0, d[a[i]].se = a[i];
    cin >> s;
    // cout << "111" << endl;
    init_st(n);
    d[ma].fi = 1;
    build(1, n, ma);
    // cout << "111" << endl;
    int f = 0;
    int yi = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            yi++;
            if (d[a[i+1]].fi == 1 || d[a[i+1]].fi == dma)
            {
                f = 1;
                break;
            }
        }
    }
    // cout << 1 << '\n';
    if (f)
    {
        cout << -1 << '\n';
        return;
    }
    // cout << 2 << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << d[i].fi << ' ' << d[i].se << '\n';
    sort(d + 1, d + n + 1);
    // for (int i = 1; i <= n;i++)
    //     cout << d[i].fi << ' ' << d[i].se << '\n';
        for (int i = n; i >= n - 4 && i >= 1; i--)
        {
            // cout << d[i].se << ' ' << '\n';
            ans[++it] = d[i].se;
        }
    int sum = 0;
    for (int i = 1; i <= it; i++)
        sum += find(ans[i]);

    if (sum >= yi)
    {
        cout << it << '\n';
        for (int i = 1; i <= it; i++)
        {

            int l = wei[ma], r = wei[ans[i]];
            if(l>r)
                swap(l, r);
            cout << l << ' ' << r << '\n';
        }
    
    }
    else
        cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}