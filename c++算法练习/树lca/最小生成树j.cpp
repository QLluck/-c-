#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4+7;
struct node
{
    int x, y, w;
} arr[N];
int me[N] = {0}, it;
int n, m;
bool sort_f(node a, node b) { return a.w < b.w; }
void add(int x ,int y,int w)
{  if(x>y)
        swap(x, y);
    arr[++it].x = x;
    arr[it].y = y;
    arr[it].w = w;
}
int find(int x )
{
     if(me[x]==x)
         return x;
    else
        return me[x] = find(me[x]);
}
int kruskal()
{
    int flag = 0;
    int ans = 0;
    int ar[N],it1=0;
    for (int i = 1; i <= it;i++)
    {
          if(find(arr[i].x)!=find(arr[i].y))
          {
              me[find(arr[i].x)] = find(arr[i].y);
              ans += arr[i].w;
                   
          }
    }
}
void solve()
{
    cin >> n >> m;
    it = 0;
    for (int i = 1; i <= n;i++)
        me[i] = i;
    for (int i = 1; i <= m;i++)
   {
       int x, y, w;
       cin >> x >> y >> w;
       add(x, y, w);
   }
   sort(arr + 1, arr + it + 1, sort_f);
  int  res = kruskal();
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}
