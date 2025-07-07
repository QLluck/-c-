#include <bits/stdc++.h>
using namespace std;
const int N = 107;
int arr[N][N] = {0};
int fl(int x )
{
    int res = 0;
    while(x)
    {
        res++;
        x /= 2;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    int flag = 0;
    int ma = 0;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        if(flag)
            continue;
        
        int floor = fl(x);
        if(floor<ma)
            flag = 1;
        else if(ma<=floor)
        {
            ma = floor;
        }
    }
    if(flag)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}