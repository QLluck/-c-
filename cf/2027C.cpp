#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N];
int ans = 0;
int n;
map<int, vector<int> > mp;
queue<int> que;
void bfs(int s)
{
    que.push(s-1);
    while(que.size())
    {
        int u = que.front();
        que.pop();
        ans = max(ans, n + u);
        for(auto p : mp[u])
        {
            if(p!=1)
            {
                que.push(p - 1 + u);
                // cout << p << ' ' << u << '\n';
            }
        }
    }
}
void solve()
{
   mp.clear();
   cin >> n;
   ans = n;
   
   for (int i =1 ; i <= n;i++)
     {
         cin >> a[i] ;
         a[i] -= (n - i + 1);
         if (a[i] >= 0)
             mp[a[i]].push_back(i);
    }
    for (auto p : mp[0])
    {
        if(p!=1)
            bfs(p);
    }
    // cout << '\n';
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
// n
//  n n-1 n-2  1
//