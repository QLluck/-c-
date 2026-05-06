#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 

const int N = 2e5+7;
int a[N];
int d[N];
vector<int> t[N];
vector<PII>tf[N];
    int n,m;
map<PII,int>mp;
int b[4];
int bfs()
{
    queue<int> que;
    for(int i=1;i<=n;i++)if(d[i]==0)que.push(i),a[i]=1;

    while(que.size())
    {
        int u = que.front();
        que.pop();

        // int ma1=0,ma2=0;
        int ma=0;
        for(int i=0;i<tf[u].size();i++)
        {
            int v1 = tf[u][i].fi;
            int v2 = tf[u][i].se;
            ma = max(ma,a[v1]+a[v2]);
            // sort(b+1,b+4);
            // ma1=b[3],ma2=b[2];
        }
        if(a[u]==0)a[u]=ma;
        for(int i=0;i<t[u].size();i++)
        {
            int v = t[u][i];
            d[v]--;
            if(d[v]==0)que.push(v);
        }
    }
    int ans =0 ;
    // for(int i=1;i<=n;i++)cout<<d[i]<<' ';
    // cout<<'\n';
    for(int i=1;i<=n;i++)
    { 
        
        if(d[i]!=0)return -1;
        ans+=a[i];
    }
    return ans;
}
void solve()
{

    cin>>n>>m;
    int f= 0 ;
    // map<>
    for(int i=1;i<=n;i++)d[i]=0,t[i].clear(),a[i]=0,tf[i].clear();
    for(int i=1;i<=m;i++)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
             t[n2].push_back(n1);
             tf[n1].push_back({n2,n3});
            d[n1]++;
            t[n3].push_back(n1);
            d[n1]++;
    }
    if(f)
    {
        cout<<-1<<'\n';
        return;
    }
     f = bfs();
    if(f>1e9)cout<<-1<<'\n';
    else 
     cout<<f<<'\n';
    
}
// a1>=a2,
// a1>=a3 
// a3>=a4
//a3>=a5

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // dui();
    // cin>>t;
    while(t--)solve();
}