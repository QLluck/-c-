// 顺序表
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size()<=2)
    {
        cout << 0 << '\n';
        return ;
    }
    ll shan = 0;
    ll xia = 0;
    for (int i = 0; i < n;i++)
    {
        if (s[i] == '-')
            shan++;
        else
            xia++;

    }
    if(shan<2||xia<1)
    {
        cout << 0 << '\n';
        return;
    }
    if(shan&1)
    {
        ll ans = (shan - 1) / 2  * (shan+1)/2  * xia;
        cout << ans << '\n';
    }
    else 
    {
        ll ans = (shan / 2 )* (shan/2)   * xia;
        cout << ans << '\n';
    }

}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}