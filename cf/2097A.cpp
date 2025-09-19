#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;

int a[N];
int b[N],it;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n;i++)
        cin >> a[i], mp[a[i]]++;
    sort(a + 1, a + n + 1);
    n=unique(a+1,a+n+1)-a-1;
    //cout << n << '\n';
    int f = 0;
    for (int i = 1; i <= n;i++)
    {
        if(mp[a[i]]>=4)
        {
            cout << "Yes" << '\n';
            return;
        }
       if (a[i] != a[i - 1] + 1)
            {
                f = 0;
              
            }
            
        if(f==0&&mp[a[i]]>=2)
            f = 1;
        else if(f==1&&mp[a[i]]>=2)
        {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
