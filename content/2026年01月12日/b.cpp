#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII  pair<int,int> 
#define fi first 
#define se second 
const int N = 5e5+7;
int a[N];
int dc[N];
int dr[N];
vector<int>t[N];
map<PII,int>mp;
int it =0 ;
int ans[N]={0};
int ans1[N],it1=0;

int sum1[N]={0};
struct node
{
    int id,l,x,r,y,num;
};
node o[N];
node o2[N];
bool so(node a,node b)
{
    return a.num <b.num ;
}
void bfs(int x)
{
    queue<int>que;
    que.push(x);
    while(que.size())
    {
        int u = que.front();
        // cout<<u<<'\n';
        que.pop();
        for(int i = 0 ;i<t[u].size();i++)
        {   
            int v = t[u][i];
            if(a[v]==1)continue;
            a[v]=1;
            // cout<<u<<' '<<v<<' '<<mp[{u,v}]<<'\n';
            
            ans[++it]=mp[{u,v}];
            // cout<<u<<' '<<v<<' '<<it<<'\n';
            que.push(v);
        }
    }
}
void debug(int x)
{
    cout<<"------\n";
    cout<<x<<'\n';
    cout<<"------\n";
}
void solve()
{
   
   int n,m;
   it =0 ;
   it1=0;
   cin>>n>>m;
   mp.clear();
   for(int i=1;i<=n;i++)a[i]=0,t[i].clear(),dc[i]=0,dr[i]=0,sum1[i]=0;
   for(int i=1;i<=m;i++)
   {
    o[i].id = i;
    cin>>o[i].l>>o[i].x>>o[i].r>>o[i].y;
    
    o[i].num = o[i].x+o[i].y;
    o2[i].l=o[i].l,o2[i].x=o[i].x,o2[i].r=o[i].r,o2[i].y=o[i].y;
    // o[i].r+=n;
   }
   sort(o+1,o+m+1,so);
   for(int i=1;i<=m;i++)
   { if(o[i].num==2)ans1[++it1]=o[i].id;
   }

// cout<<"yes"<<'\n';
    for(int i=1;i<=m;i++)
    {
        if(o[i].num==4)
        { a[o[i].l]=1,a[o[i].r]=1;
        }
        else if(o[i].num==3)
        {int u,v;
            if(o[i].x<o[i].y) u=o[i].l,v=o[i].r;
            else u=o[i].r,v=o[i].l;
            a[u]=2;
            if(mp[{u,v}]==0)
            { t[u].push_back(v),mp[{u,v}]=o[i].id;
            // cout<<"uv: "<<u<<' '<<v<<' '<<i<<'\n';
            dc[u]++,dr[v]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)bfs(i);
    }
    for(int i=1;i<=n;i++)if(a[i]==2&&dr[i]==0)bfs(i);
    for(int i=1;i<=n;i++)if(a[i]==2)bfs(i);

    map<int,int>mp1;
    for(int i=1;i<=it;i++)
    {
        mp1[ans[i]]=1;
    }
    //
    // cout<<"YES"<<'\n';
    // debug(it1);
    for(int i=1;i<=m;i++)
    {
        if(o[i].num==3 && mp1[o[i].id]==0)ans1[++it1]=o[i].id;
    }
    // debug(it1);
    //  cout<<"YES"<<'\n';
    for(int i=it;i>=1;i--)
    { ans1[++it1]=ans[i];
        // cout<<it<<' '<<ans[i]<<'\n';
    }
    //  cout<<"YES"<<'\n';
    //
   for(int i=1;i<=m;i++)
   {
    if(o[i].num==2 || o[i].num==3)continue;
    else 
    { 
        ans1[++it1]=o[i].id;
        // cout<<it1<<' '<<o[i].id<<'\n';
    }
   }
   int sum2 =0 ;
   for(int i=1;i<=m;i++)
   {
        int id = ans1[i];
        sum1[o2[id].l]=o2[id].x;
        sum1[o2[id].r]=o2[id].y;

   }
   for(int i=1;i<=n;i++)sum2+=sum1[i];
   cout<<sum2<<'\n';
//  debug(it1);
   for(int i=1;i<=it1;i++)cout<<ans1[i]<<' ';
   cout<<'\n';





   
}
int f(int x)
{
    PII a[11];
    for(int i=1;i<=9;i++)a[i].fi=0,a[i].se=i;
    while(x)
    {
         a[x%10].fi+=1;
         x/=10;
    }
    sort(a+1,a+9+1);
    return a[9].se;
}
void te()
{
    int n;
    cin>>n;
    int ans =0 ;
    for(int i=1;i<=n;i++)
    {
    ans +=f(i);
    }
    cout<<ans<<'\n';
}
signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  t =1;
  cin>>t;
  while(t--)
  solve();
    // te();
}