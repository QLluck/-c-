#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+7;
int a[N] = {0};
int b[N] = {0};
void solve()
{

    int n, m;
    cin >> n >> m;
    int sum = 0;
    
    for (int i = 1; i <= n;i++)
     {   cin >> a[i];
         a[i] = a[i] % m;
         //sum += a[i];
     }
    for (int i = 1; i <= n;i++)
     {   cin >> b[i];
         b[i] = b[i] % m;
         //sum += b[i];
     }
     sort(a + 1, a + n + 1);
     sort(b + 1, b + n + 1);
     int it = 0;
     while(a[it]==0&&it<=n)
         it++;
     for (int i = it,j=n; i <= n;i++,j--)
     {
         sum += (a[i] + b[j]) % m;
     }
     for (int i = 1; i < it;i++)
         sum += b[i];
         cout << sum  << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}
