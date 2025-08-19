#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 

const int N = 200+7;
int a[5][N];
pii ans[10000];
int it;
void print(int n)
{
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
void solve()
{  int n;
    cin>>n;
    it=0;
    for(int i=1;i<=n;i++)cin>>a[1][i];
    for(int i=1;i<=n;i++)cin>>a[2][i];
    int itn = 1;
    while(itn<=2*n)
    {  int x,y;
     for(int i=1;i<=2;i++)
     {
        for(int j=1;j<=n;j++)
        {
           if(itn==a[i][j])x=i,y=j;
         }
      }
      int sx = (itn&1)?1:2;
      int sy = ((itn+1)/2);
      if(sx!=x)ans[++it].fi=3,ans[it].se=y,swap(a[1][y],a[2][y]);
      for(int i = y-1;i>=sy;i--)
      {   ans[++it].fi=sx;
          ans[it].se=i;
          swap(a[sx][i],a[sx][i+1]);
      }
      //cout<<sx<<' '<<sy<<' '<<x<<' '<<y<<'\n';
       // print(n);

      itn++;


   }
   cout<<it<<'\n';
   for(int i=1;i<=it;i++)cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
   
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