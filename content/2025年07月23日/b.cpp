#include<bits/stdc++.h>
using namespace std;
#define int long long
const double pi = 3.1415926535;
const int N = 1e5+7;
vector<int> t[N];
int me[N]={0};
int w[N]={0};
int ans[N]={0};
map<int,int>mp;

int yi(int x);
void bfs()
{
     queue<int > que;
     que.push(1);
     ans[1]=w[1]; 
     me[1]=1;
      mp[yi(w[1])]++;
      //cout<<yi(w[1])<<' '<<mp[yi(w[1])]<<'\n';
     while(que.size())
     {
         int u =que.front();
         que.pop();
         for(int i =0 ;i <t[u].size() ;i++)
         {
              int v1 = t[u][i];
              if(me[v1])continue;
              me[v1]=1;
              mp[yi(ans[u])]++;
             // cout<<mp[yi(ans[u])]<<' '<<yi(ans[u])<<'\n';
              ans[v1] = ans[u]&w[v1];
              que.push(v1);
         }
     }
}
int yi(int x)
{
              int res =0 ;
         while(x)
         {
             if(x&1)res++;
             x>>=1;
         }
        return res;
}
void solve()
{
      int n,q;
      cin>>n>>q;
      for(int i=1;i<=n;i++)cin>>w[i];
      for(int i=1;i<=n-1;i++)
      {
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
      }
      bfs();
      for(int i =1;i<=q; i++)
      {
         int x;
         cin>>x;
         cout<<mp[x]<<'\n';

      }
   
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}