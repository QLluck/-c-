// 顺序表
#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    if(abs(n*p) <abs(k) )
    {
        cout << -1 << '\n';
        return;
    }
    int ans = ceil((double)(abs(k)) / p);
    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}