#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
pii a[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    int sum  =0 ;
    for(int i=1;i<=n;i++)
    {
        int x,f;
        cin>>x>>f;
        if(x==m)
        {
            if(f<60)a[i].fi=x,a[i].se=60,sum+=60;
            else a[i].fi=x,a[i].se=f,sum+=f;
        }
        else a[i].fi=x,a[i].se=f,sum+=f;
    }
    sort(a+1,a+n+1);
    double avg = (double)sum/n;
    for(int i=1;i<=n;i++)
    {
         if(m!=a[i].fi&&a[i].se>=avg&&a[i].se>=2)a[i].se-=2;
    }
    for(int i=1;i<=n;i++)cout<<a[i].se<<' ';
    cout<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}