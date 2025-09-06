#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
int a[N];

void solve()
{
    int n,k;
    cin>>n>>k;
   int it=2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(it<=n&&a[it]==1)it++;
    it-=2;
    if(n==k)
    {      
        for(int i=2;i<=n;i+=2)
        {
            if(a[i]!=(i/2))
            {
                cout<<i/2<<'\n';
                return;
            }
        }
        cout<<k/2+1<<'\n';
        return;
    }
    int yu = n-k;
    if(yu>=it)cout<<1<<'\n';
    else 
    {
        cout<<2<<'\n';
    }
    
    

}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}