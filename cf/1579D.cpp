#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
int arr[N] = {0};
struct node
{
    int first, second;
};
node ans[N];
int it = 0;
priority_queue<pair<int, int>> que;
void solve()
{
    int n;
    cin >> n;
    while (!que.empty())
        que.pop();
    it = 0;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        pair<int, int> a;
        a.first = num;
        a.second = i;
     if(a.first!=0)
        que.push(a);
    }
 
    while (que.size() > 1)
    {
        pair<int, int> a = que.top();
        que.pop();
        pair<int, int> b = que.top();
        que.pop();
        ans[++it].first = b.second;
        ans[it].second = a.second;
        
        if(--a.first)
            que.push(make_pair(a.first, a.second));
        if(--b.first)
            que.push(make_pair(b.first, b.second));
        
    }

    cout << it << '\n';
    for (int i = 1; i <= it; i++)
    {
        

            cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}