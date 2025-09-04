#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 

const int N = 2e5+7;
vector<int> a[N];
int r[N]={0};
int c[N]={0};
pii id [4];
int it;
void solve()
{  int n,m;
     cin>>n>>m;
      
    //  for(int i=0;i<=m;i++)y[i].fi = 0,y[i].se = N ;
    //  for(int i=0;i<=n;i++) x[i].fi =0,x[i].se=N;
    it =0 ;
    int ma =0;
    for(int i=1;i<=n;i++)a[i].resize(m+3,0),r[i]=0;
    for(int i =1;i<=m;i++)c[i]=0;
    for(int i=1;i<=n;i++)
    {
         for(int j =1;j<=m;j++)
         {
           
                cin>>a[i][j];
                ma = max(a[i][j],ma);
         }
    }
    int num =0 ;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
         if(ma==a[i][j])
         {
             num++;
             r[i]++;
             c[j]++;
         }
    }
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=m;j++)
         {
              int tmp = r[i] +c[j] - (a[i][j]==ma);
              if(tmp==num)
              {
                cout<<ma-1<<'\n';
                return;
              }
         }
    }

    cout<<ma<<'\n';
    


   
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}