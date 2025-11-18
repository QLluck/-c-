#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
vector<int> t[N];
// vector<int> t2[N] ;
int d[N] = {0};
int dn[N] = {0};
map<PII, int> mp;
queue<int> que;
int n, k;
void bfs()
{
    // map<PII, int> me;

    // map<int, int> me;
    while (que.size())
    {
        int u = que.front();
        // int sum = que.front().fi;
        
        que.pop();
        for (int i = 0; i < t[u].size(); i++)
        {
            int v = t[u][i];
            if (d[v] == 0)
                continue;
            mp[{u, v}] = n - dn[u]-1;
            mp[{v, u}] = dn[u] + 1;

            dn[v] += dn[u] + 1;
            
            d[v]--;
            d[u]--;
            if(d[v]==1)
            que.push( v);
        }
    }
}
void solve()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        t[i].clear();
        d[i] = 0;
        dn[i] = 0;
    }
    mp.clear();
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
            que.push( i);
    }
    bfs();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int f = 0;
        for (int j = 0; j < t[i].size(); j++)
        {
            int v = t[i][j];
            int num = mp[{i, v}];
            if ((n - num - 1) >= (k - 1))
            {
                // f = 1;
                sum += num  ;
            }
            //  cout << i << ' ' << v << ' ' << num << ' ' << sum << '\n';

        }
        //  sum/=2;
            sum++;
        // cout<<i<<' '<<sum<<'\n';
        ans += sum;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}