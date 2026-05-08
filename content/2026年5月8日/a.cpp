#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int a[N];
int b[N];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n;i++)
        cin >> a[i],b[i]=0;
    for (int i = 1; i <= n;i++)
    {
        int mi = 1e9 + 7;
        int it = 0;
        for (int j = i+1; j <= n;j++)
        { 
            
            if((i+j)%2==0)
                {
                    int num = a[(i + j) / 2];
                    if(mi > num)
                    {
                        mi = num;
                        it = j;
                    }
                }
            else
           {     int num= a[(i + j) / 2] + a[((i + j) / 2 + 1)] ;
               if (mi > num)
               {
                   mi = num;
                   it = j;
               }
           }
        }
        if(mi==1e9+7)
            mi = 0;
        else {
        ans += mi;
        b[i] = it, b[it] = it;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}
// 1 2 3 4 4 3 3 2 2 1 1 1 2 2 4 4 5 6 4 4 3 3 2 2 1