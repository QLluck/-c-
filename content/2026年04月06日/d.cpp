#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e3+100;
#define fi first 
#define se second 
#define PII pair<int,int>
const int INF = 1e18;
int a[N];

// string s[N];
vector<PII> t[N];
int n,m,k,D;
int d[N];
PII ans[N];
int mi[N];
int f(string &s,int p)
{
    int res=0;
    if(s[0]=='G')p=1;
    for(int i = p ;i<s.size();i++)
    {
        res*=10;
        res+=s[i]-'0';
    }
    if(s[0]=='G')res+=n;
    return res;
}
   
void bfs(int s)
{
    for(int i=1;i<=n+m;i++)d[i]=INF;
    d[s]=0;
    priority_queue<PII> que;

    que.push({0,s});
    while(que.size())
    {
        int u= que.top().se;
        int uw = -que.top().fi;
        que.pop();
        for(int i=0;i<t[u].size();i++)
        {
            int v = t[u][i].fi;
            int w = t[u][i].se;
            if(d[w]+d[u]<d[v])
            {
                d[v]=d[w]+d[u];
                que.push({-d[u],v});
            }

        }
    }
    
} 
bool f2(PII a,PII b)
{
    if(a.fi==b.fi)return a.se<b.se;
    else return a.fi<b.fi;
}
void solve()
{


cin>>n>>m>>k>>D;
for(int i=1;i<=k;i++)
{

    string su,sv,sw;
    int u= f(su,0),v=f(sv,0),w=f(sw,0);
    t[u].push_back({v,w});
    t[v].push_back({u,w});
}

int it =0 ;

for(int i=1;i<=m;i++)
{
    int num = n+i;
    bfs(i);
    int f=0 ;
    int sum =0;
    int mii = 1e18+7;
    for(int j=1;j<=n;j++)
    {
            if(D<d[j]||d[j]==INF)f=1;
            sum+=d[j];
            mii=min(mii,d[j]);
    }
    if(f==0)
    {
        it++;
        ans[it].fi=sum;
        ans[it].se=i;
        mi[it]=mii;
    }

}
    sort(ans+1,ans+it+1,f2);
    if(it==0)cout<<"No Solution"<<'\n';
    else 
    {
        int num = ans[1].fi;
        int id = ans[1].se;
        double xiao = (double)num/(n);
        cout<<'G'<<id<<'\n';
        cout<<xiao<<' ';

    }
 
  

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
    // string s1 ="123";
    // string s2 = "23";
    // cout<<(s1<s2)<<'\n';
    
}