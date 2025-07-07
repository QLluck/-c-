#include<bits/stdc++.h>
using namespace std ;
const int N = 107;
int arr[N][N] = {0};
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i<=n; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        for (int j = l1; j <= l2;j++)
        {
            int num =( j == l2 ? r2 : d);
            int g = (j == l1 ? r1 : 1);
            
            for ( ; g <= num;g++)
              {  arr[j][g] = 1;
                 // cout << j << ' ' << g << '\n';
              }
        }
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= d;j++)
        {
             if(arr[i][j]==0)
             {
                 cout << i << ' ' << j << '\n';
                 return;
             }
        }
    }
    cout << "Online" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}