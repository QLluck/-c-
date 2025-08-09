#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 1e6+7;
int n,m,k;
vector<int> a[N];
vector<int>  me[N];
int flag =0;
priority_queue<pair<int,pii> > que;
int rx[4]={0,1,0,-1};
int ry[4]={1,0,-1,0};
void bfs()
{  que.push({0,{1,1}});

   me[1][1]=0 ;

    while(que.size())
    {
         if(flag)
         {
            que.pop();
            continue;
         }
         pair<int,pii> u = que.top();
         u.fi = -u.fi;
         que.pop();
         if(u.se.fi==n&&u.se.se==m)
         {
                   flag=1;
                   continue;
         }
         for(int i=0;i<4;i++)
         {
             int x1 = u.se.fi +rx[i];

             int y1 = u.se.se + ry[i];

             int biao = a[u.se.fi][u.se.se];

              if(x1<=0||x1>n||y1<=0||y1>m)continue;

              int k1 = (i==biao)?u.fi : u.fi-1;

              if(k1<=me[x1][y1])continue;
           if(me[x1][y1]>me[u.se.fi][u.se.se]+k1)
           {
              me[x1][y1]= me[u.se.fi][u.se.se]+k1 ;
              que.push({-k1,{x1,y1}});

           }
              //cout<<x1<<' '<<y1<<'\n';

         }

    }
    
}
void solve()
{
     cin>>n>>m>>k;
     flag =0;
     for(int i=1;i<=n;i++)a[i].resize(m+2),me[i].resize(m+2);
    //  for(int i=1;i<=n;i++)
    //  {
    //     for(int j=1;j<=m;j++)cout<<me[i][j]<<' ';
    //     cout<<'\n';
    //  }

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        { //cin>>a[i][j];
            char c ;
            cin>>c;
            if(c=='R')a[i][j]=0;
            else if(c=='D')a[i][j]=1;
            else if(c=='L')a[i][j]=2;
            else if(c=='U')a[i][j]=3;
            me[i][j]= 1e9+1 ;
        }
     }
    //       for(int i=1;i<=n;i++)
    //  {
    //     for(int j=1;j<=m;j++)cout<<me[i][j]<<' ';
    //     cout<<'\n';
    //  }
     bfs();
    if(flag==1)
    cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
     

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}