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
vector<int> t[N];
int it;
queue<int> que;
map<int,int>mp;
void bfs()
{    map<int,int>me;
      for (auto p : t[mp[0]])
    {
        
             que.push(p-1);
            me[p]=1; 
    }

    while(que.size())
    {
        int u = que.front();
        que.pop();
        ans = max(ans, n + u);
        if(mp[u]==0)continue;
        // cout<<u<<'\n';
        for(auto p : t[mp[u]])
        {  
            // cout<<p<<'\n';
            if(me[p])continue;
            me[p]=1;
        
            
                que.push(p - 1 + u);
                // cout << p << ' ' << u << '\n';
            
        }
    }
}
void solve()
{
   it=0;
   mp.clear();
   cin >> n;
   ans = n;
   
   for (int i =1 ; i <= n;i++)
     {
         cin >> a[i] ;
         a[i] -= (n - i + 1);
         if (a[i] >= 0)
             {
                  if(mp[a[i]]==0)
                  {
                    mp[a[i]]= ++it;
                    // cout<<it<<' '<<' '<<a[i]<<' '<<'\n';
                    t[it].clear();
                    t[it].push_back(i);

                  }
                  else
                  {  t[mp[a[i]]].push_back(i);
                    // cout<<mp[a[i]]<<' '<<a[i]<<' '<<'\n';
                  }
             }
    }
    bfs();
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