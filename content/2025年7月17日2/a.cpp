#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int arr[N] = {0};
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> arr[i];
    for (int i = 1; i <= n;i++)
    {
        arr[i] = arr[i] + arr[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        if(i+k-1<=n&&arr[i+k-1]-arr[i-1]==0)
            ans++,i++;

    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}