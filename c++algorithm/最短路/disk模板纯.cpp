#include <iostream>
#include<algorithm>

using namespace std;
const int N = 1e3 + 7;
const int inf = 1e9 + 7;
int e[N][N] = {0},me[N]={0} ,d[N]={0};
int n;

void disk(int s)
{
    for (int i = 0; i <= n;i++)
        d[i] = inf;
    d[s] = 0;
    for (int i = 1; i <=n;i++)
    {
        int u = 0;
        
        for (int j = 1; j <= n;j++)
        
              if(!me[j]&&d[j]<d[u])
                 u = j;
        me[u] = 1;
        for (int j = 1; j<= n;j++)
        {
              if(e[u][j]!=inf)
              {
                  int w = e[u][j];
                  if(d[j]>d[u]+w)
                      d[j] = d[u] + w;
              }
        }
    }
}
void solve()
{
    int m;
    cin >> m >> n;
    for (int i = 1; i <= n;i++) 
    {
        for (int j = 1; j <= n;j++)
            e[i][j] = inf;
    }
        for (int i = 1; i <= m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            e[a][b] = e[b][a] = min(e[a][b], c);
        }
    disk(1);
    cout << d[n] ;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}