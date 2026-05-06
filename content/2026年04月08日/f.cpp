#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
// string a[N];
vector<int> t[N];
 int l,n;
PII a[N];
int it =0;
int rx[2]={1,0};
int ry[2]={0,1};

void bfs()
{
    it=0;
   queue<PII> que;
   que.push({1,1});
   map<PII,int>mp;
   mp[{1,1}]=1;
   a[++it].fi=1;
   a[it].se=1;
   while(que.size())
   {
    int x= que.front().fi;
    int y =que.front().se;
    que.pop();
    for(int i=0;i<2;i++)
    {
        int x1= x+rx[i];
        int y1 = y+ry[i];
        if(x1<=0||y1<=0||x1>n||y1>n||mp[{x1,y1}])continue;
        mp[{x1,y1}]=1;
        a[++it].fi=x1;
        a[it].se=y1;
        que.push({x1,y1});
        
    }
   }
}
int ans= 0 ;
int mx[10];
int my[10];
int b[50][50];
void dfs(int d)
{
    // if(d>it)ans++;
     if(d>it)
    {
        int f =1;
        for(int i=1;i<=n;i++)
        {
            int sum =0 ;
            for(int j=1;j<=n;j++)
            {
                sum+=b[i][j];
            }
            if(sum!=l)return;
        }
        for(int j=1;j<=n;j++)
        {
            int sum =0 ;
            for(int i=1;i<=n;i++)
            {
                sum+=b[i][j];
            }
            if(sum!=l)return;
        }
        ans++;

    }
    
    int x=a[d].fi;
    int y = a[d].se;
    for(int i1=0 ;i1<=l;i1++)
    {
        
       b[x][y]=i1;
           dfs(d+1);
    }

    

}
void solve()
{
    // int a,b;
    // int l,n;
    cin>>l>>n;
    bfs();
    // cout<<it<<'\n';
    dfs(1);
    cout<<ans<<'\n';
  
   
     
    


//  
}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    solve();
}