#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
pii r[N];
pii c[N];
pii a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        //int x, y;
        cin >> a[i].fi >> a[i].se;
        r[i].fi = a[i].fi, r[i].se = i;
        c[i].fi = a[i].se, c[i].se = i;
    }
    sort(r + 1, r + n + 1);
    sort(c + 1, c + n + 1);
    int ans = (r[n].fi - r[1].fi + 1) * (c[n].fi - c[1].fi + 1);
    for (int i = 1; i <= n;i++)
    {
        int rmi = r[1].fi;
        if(r[1].se==i&&n>=2)
            rmi = r[2].fi;
        int rma = r[n].fi;
        if(r[n].se==i&&n>=2)
            rma = r[n - 1].fi;
        int cmi = c[1].fi;

        if(c[1].se==i&&n>=2)
            cmi = c[2].fi;
        
        int cma = c[n].fi;
        if(c[n].se==i&&n>=2)
            cma = c[n - 1].fi;
        int shen = (rma - rmi + 1) * (cma - cmi + 1) - n;
        if(shen>=0)
        ans = min(ans, (rma - rmi + 1) * (cma - cmi + 1));
        else 
        {
            ans = min(ans, (rma - rmi + 1) * (cma - cmi + 2));
            ans = min(ans, (rma - rmi + 2) * (cma - cmi + 1));
        }
        //cout << rma << ' ' << rmi << ' ' << cma << ' ' << cmi << '\n';
    }
    //ans = max(n, ans);
    cout << ans << '\n';
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