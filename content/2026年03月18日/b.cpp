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
vector<int>tf[N];
    int n,m;

int w[N];
int num[N];
    // int n;
bool sor(int a,int b)
{   if(w[a]==w[b])return num[a]>num[b];
    else return w[a]*(num[b]+1)<w[b]*(num[a]+1);
}
void bfs()
{
    queue<int> que;
    // for(int i=1;i<=n;i++)cout<<d[i]<<' ';
    // cout<<"\n";
    for(int i=1;i<=n;i++)
    {   
        if(d[i]==0)que.push(i);
        num[i]=1;
    }


    while(que.size())
    {
        int u = que.front();
        // cout<<u<<'\n';
        que.pop();
        for(int i = 0 ;i <t[u].size();i++)
        {
            int v = t[u][i];
            w[v]+=w[u];
            num[v]+=num[u];
            // cout<<num[v]<<'\n';
            d[v]--;
            if(d[v]==0)que.push(v);
        }
    }
}
int ans =0 ;
int it =0 ;
void dfs(int u)
{
    it++;
    ans+=it*a[u];
    for(int i=0;i<tf[u].size();i++)
    {
        int v = tf[u][i];
        cout<<v<<' '<<'\n';
        dfs(v);
    }
}
void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],w[i]=a[i],d[i]=0,num[i]=0;
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        t[i].push_back(f);
        tf[f].push_back(i);
        d[f]++;
    }

    bfs();
    for(int i=1;i<=n;i++)
    {
        sort(tf[i].begin(),tf[i].end(),sor);
        for(int j=0 ;j<tf[i].size();j++)cout<<tf[i][j]<<'\n';
        cout<<'\n';
    }
            for(int i=1;i<=n;i++)cout<<w[i]<<' ';
    cout<<"\n";
    dfs(1);
    for(int i=1;i<=n;i++)cout<<num[i]<<' ';
    cout<<'\n';
    cout<<ans<<'\n';
    
    
    
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