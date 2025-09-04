#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;

void solve()

{
    int n;
    cin >> n;
    string s;
    cin >> s;
    //int f = 0;
    int sn = 0;
    int pn = 0;
    for (int i = 0;i<n;i++)
    { 
        if(i==n-1&&s[i]=='p')
            continue;
        if(i==0&&s[i]=='s')
            continue;
        if(s[i]=='s')
            sn++;
        else if(s[i]=='p')
            pn++;
    }
   if(pn&&sn)
       cout << "NO" << '\n';
       else
           cout << "YES" << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}