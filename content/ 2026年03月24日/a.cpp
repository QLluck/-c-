#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 5e5+7;

int me[N];
int find(int x)
{
    if(me[x]==x)return x;
    else return me[x]=find(me[x]);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    // a.clear();
    priority_queue<pair<int,PII>> a;
    for(int i=0;i<=n;i++)me[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a.push({-w,{u,v}});
    }
    int ans =0 ;
    for(int i=1;i<=m;i++)
    {
        int u = a.top().se.fi;
        int v = a.top().se.se;
        int w = -(a.top().fi);
        int x = find(u),y=find(v);
        a.pop();
        if(x!=y)ans+=w,me[x]=y;

    }
    cout<<ans<<'\n';

    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
    t=1;
    // cin>>t;
    while(t--)
    solve();
}