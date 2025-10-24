#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
vector<int> a[N];

void solve()
{
    int n, m;
    cin>>n>>m;
    int Max = 0;
    for (int i = 1; i <= n;i++)
        a[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;

            for (int j = 1; j <= l;j++)
            {
                int tmp;
                cin >> tmp;
                a[i].push_back(tmp);
            }
            sort(a[i].begin(), a[i].end());
            int mex = 0;
            int f = 0;
            for(auto p :a[i])
            {
                // cout << p << ' '<<mex<<'\n';
                if(mex>p)
                    continue;
                else if(mex==p)
                    mex++;
                else 
                {
                    if(f==1)
                        break;
                    mex++;
                    f++;
                    if(mex==p)
                        mex++;
                }
            }
            if(f==0)
                mex++;
            Max = max(Max, mex);
        }
        int ans = 0;
        int n1 = min(m, Max);
        int n2 = max(0LL, m - Max);
        // cout << Max << ' ' << n1 << ' ' << n2 << '\n';
        ans = (n1+1) * Max + (Max + 1 + m) * n2 / 2;
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
