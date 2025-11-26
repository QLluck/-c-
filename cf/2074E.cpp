#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
mt19937_64 rng(random_device{}());
void solve()
{
    int n;
    scanf("%d", &n);
    int a = 1, b = 2, c = 3;
    int hui;
    // cout << "? " << 1 << ' ' << ans << " " << n << endl;
    printf("%c %lld %lld %lld\n",'?',a, b, c);
    fflush(stdout);
    // cin >> hui;
    scanf("%lld", &hui);
    while (hui)
    {
        int tmp = rng() % 3 + 1;
        if(tmp==1)
            a = hui;
        else if(tmp==2)
            b = hui;
        else
            c = hui;
        printf("%c %lld %lld %lld\n", '?', a, b, c);
        fflush(stdout);
        // cin >> hui;
        scanf("%d", &hui);
    }
    printf("%c %lld %lld %lld\n", '!', a, b, c);
    fflush(stdout);
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    // cin >> t;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
}