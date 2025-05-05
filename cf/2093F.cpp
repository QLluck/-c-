#include<bits/stdc++.h>
using namespace std ;
const int N = 507;
string arr[N][N];
string b[N];
pair<int, int> pai[N];
bool cmp(pair<int,int> a ,pair<int,int> b)
{
    return a.first > b.first;
}
void solve()
{
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j<= n;j++)
            cin >> arr[i][j];
    }
    map<int, int> mp;
    for (int i = 1; i <= m;i++)
    {
        int num = 0;
        for (int j = 1; j <= n;j++)
        {
                 if(b[j]==arr[i][j])
                     num++;
        }
        pai[i].first = num;
        pai[i].second = i;
    }
    sort(pai + 1, pai + m + 1,cmp);
    int num = 0;
    int ans = 0;
    for (int i = 1; i <= m;i++)
    {
        int it = pai[i].second;
        if(i==1)
        {
            ans += n;
            num += pai[i].first;
            for (int j = 1; j <= n;j++)
            {
                 if(arr[it][j]==b[j])
               {
                   mp[j] = 1;
               }
            }
        }
        else
        {
            for (int j = 1; j <= n;j++)
            {
                 if(mp.count(j))
                     continue;
                  if(b[j]==arr[it][j])
                  {
                      num++;
                      ans+=2;
                      mp[j] = 1;
                  }
            }
        }
       if(num==n)
       {
           cout << ans << '\n';
           return;
       }
    }
    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}