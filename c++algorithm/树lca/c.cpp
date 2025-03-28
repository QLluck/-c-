#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include<algorithm>
using namespace std;
const int N = 1e3 + 7;
vector<int> t[N];
int de[N] = {0}, fa[N][27] = {0};
int me[N] = {0};
// lca
void dfs(int u, int fat)
{
    de[u] = de[fat] + 1;
    fa[u][0] = fat;

    // cout<<u<<'\n';
    // cout<<fa[2][0]<<'\n' ;

    for (int i = 1; i <= 24; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    //   if(u==2)
    //      {
    //           cout<<"YES"<<'\n';
    //      }
    // cout<<"-----"<<'\n';
    for (int i = 0; i < t[u].size(); i++)
        if (t[u][i] != fat)
            dfs(t[u][i], u);
}
// map<int,int> mp;
int lca(int u, int v)
{
    if (de[u] < de[v])
        swap(u, v);
    for (int i = 24; i >= 0; i--)
    {
        if (de[fa[u][i]] >= de[v])
            u = fa[u][i];
    }

    if (u == v)
        return v;
    for (int i = 24; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];

    return fa[u][0];
}
// int dian(int n )
// {
//      for(int i =1 ;i<=n ;i++)if(!mp.count(i)) return i;
//      return 0 ;
// }

void solve()
{
    int n;
    map<int,int> mp;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int x, xn;

        scanf("%d:(%d)", &x, &xn);
       // printf("%d %d\n", x, xn);
        for (int j = 1; j<=xn; j++)
        {
            int y;
            scanf("%d", &y);
            t[y].push_back(x);
           t[x].push_back(y);
           mp[y] = 1;
          // printf("%d\n", y);
        }
    }
    int s=1 ; 
    while(mp.count(s))
        s++;

    dfs(s, 0);

    int m;
    scanf("%d", &m);

    // cout<<"??"<<fa[2][0]<<'\n';
    // for(int i=0 ;i<t[4].size() ; i++)cout<<t[4][i]<<' ' ;
    vector<int> ans;
    for (int i = 1; i <= m;i++)
{
        int x, y;

        scanf(" (%d %d)", &x, &y);

        //  printf("%d %d\n", x, y);
          int a = lca(x, y);
          if (!me[a])
              ans.push_back(a);
          me[a]++;
          //printf("%d\n", a);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        printf("%d:%d\n", ans[i], me[ans[i]]);
}
int main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}