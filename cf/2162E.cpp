#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
PII a[N] ;
int b[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
     {   a[i].fi = 0,a[i].se=i;
     }
    for (int i = 1; i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        a[tmp].fi++;
        b[i] = tmp;
    }
    sort(a + 1, a + n + 1);
    int it = 1;
    // cout << a[1].fi <<' '<<a[1].se<<' '<< '\n';
    if(a[1].fi==0)
    {
        int num = a[2].se;
        int it1 = 1;
        int itn = 2;
        while(num==a[1].se || num==b[n])
        {
            itn++;
            num = a[itn].se;
        }
        while (it1 <= k)
        {
            int s = it1 % 3;
            if(s==0)
                s = 3;
            // cout << s << '\n';
            if(s==1)
                cout << a[1].se << ' ';
            else if(s==2)
                cout << num << ' ';
                else if(s==3)
                    cout << b[n] << ' ';
            it1++;
        }
    }
    else 
    {
      
        int it1 = 1;
        while (it1 <= k)
        {
            int s = it1 % 3;
            if (s == 0)
                s = 3;
            cout << b[s] << ' ';
            it1++;
        }
    }
    cout << '\n';
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