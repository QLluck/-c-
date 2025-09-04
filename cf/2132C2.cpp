#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
vector<int> a[507];
int me[100], it;
int po(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
            res = res * a;
        b >>= 1;
        a *= a;
    }
    return res;
}
void solve()
{
    it = 0;
    int n, k;
    cin >> n >> k;
    int yi = 0;
    int ans = 0;
    while(n)
    {
        me[it] = 0;
        me[it] = n % 3;
        yi += me[it];
        
        n /= 3;
        ans += me[it]*( po(3, it + 1) + (it ? it * po(3, it - 1) : 0));
        cout << it << ' ' << ans << '\n';
        it++;
       
    }
    if(k<yi)
        cout << -1 << '\n';
        else
            cout << ans << '\n';
}

// 3 + x/3 per 1 ;3^x;

signed main()
{
     ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    // while (t--)
    //     solve();
    cout << 1 << ' ' << 1 << '\n';
    for (int i = 1; i <= 10; i++)
    {
        cout << po(3, i) << ' ' << po(3, i+ 1) + (i ? i * po(3, i - 1) : 0) << '\n';
    }
}
