/* ========================================= */
/* 题目名称：1706A */
/* 创建时间：2026-02-03 21:40:17 */
/* 完成时间：未完成 */
/* 备注：800 */
/* ========================================= */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int b[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)b[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int l= a[i];
        int r = m+1-l;
        if(l>r)swap(l,r);
        if(b[l])b[r]=1;
        else b[l]=1;
    }
    for(int i=1;i<=m;i++)
    { if(b[i])cout<<'A';
        else cout<<'B';
     
    }
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}