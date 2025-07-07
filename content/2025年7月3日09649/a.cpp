#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int arr[N] = {0};
int dix[N] = {0};

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n;i++)
    {
        int a;
        cin >> a;
        mp[a]++;
        dix[i] = 0;
     }
     dix[0] = 0;
     int it = 0;
    
     while(mp[it]!=0)
     {
        
         it++;
     }
     for (int i = 0; i <= it;i++)
     {
         dix[i]++;
         dix[n - mp[i] + 1]--;
     }
     for (int i = 1; i <= n;i++)
     {
         dix[i] = dix[i - 1] + dix[i];
     }
     for (int i = n; i >= 0; i--)
         cout << dix[i] << ' ';
     cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}