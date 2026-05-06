#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e6+7;
pair<int, pair<int ,PII> > a[N];
int ans[N];
int me[N];
int find(int x)
{
    if(me[x]==x)return x;
    else return me[x]=find(me[x]);
}
bool f(pair<int, pair<int ,PII> > a,pair<int, pair<int ,PII> > b)
{
    if(a.se.fi==b.se.fi)return a.se.se.fi<b.se.se.fi ;
    else return a.se.fi<b.se.fi ;
}
void solve()
{
 
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)ans[i]=0,me[i]=i;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].se.se.fi >>a[i].se.se.se;
        a[i].fi=i;
        a[i].se.fi = a[i].se.se.se-a[i].se.se.fi+1;

    }
    sort(a+1,a+n+1,f);
    for(int i=1;i<=n;i++)
    {
        int x = a[i].se.se.fi;
         x = find(x);
        int y = find(x+1);
        if(x>a[i].se.se.se)continue;
        me[x]=y;
        ans[x]=a[i].fi;
    }
    int num =0 ;
    for(int i=0;i<=n;i++)
    { if(ans[i])num++;
        else break;
    }
    cout<<num<<'\n';
    for(int i=0;i<=n;i++)
    {
        if(ans[i])cout<<ans[i]<<' ';
        else 
        {
            cout<<'\n';
            return;
        }
    }
    

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}