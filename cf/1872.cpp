#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int P = 1e9 + 7;
const int N = 1e7 + 7;
int prime[N], it;
int me[N] = {0};
void pri()
{
    me[1] = 0;
    me[0] = 0;
    for (int i = 2; i < N; i++)
    {
        if (!me[i])
            prime[it++] = i;

        for (int j = 0; j < it; j++)
        {
            if (i * prime[j] >= N)
                break;
            me[i * prime[j]] = i;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
  
            // cout << me[r] << endl;
        while(l<=r)
        {
            if (me[r] == 0)
                ;
            else
            {
                cout << r - me[r] << ' ' << me[r] << endl;
                return  ;
            }
            r--;
        }
       cout<<-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    pri();
    cin >>t;
    while (t--)
        solve();
}