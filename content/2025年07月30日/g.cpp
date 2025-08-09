#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first
#define se second
const int P = 1e9+7;
const int N = 100+7;
const int INF = 1e18+7;
vector<int> t[N];
int me[N]={0};
int b[N]={0};
int a[N]={0};
void bfs()
{
     me[1]=1;
     queue<int> que;
     que.push(1);
     while(que.size())
     {
         int u = que.front();
         que.pop();
         for(int i =0 ; i <t[u].size() ;i++)
         {
            int v = t[u][i];
            
         }
     }
}
void solve()
{ 
 
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
    {
         int u,v;
         cin>>u>>v;
         t[u].emplace_back(v);
         t[v].emplace_back(u);
    }
    bfs();

    



}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    //int t;
    
    // cin>>t;
    // while(t--)
    solve();
}