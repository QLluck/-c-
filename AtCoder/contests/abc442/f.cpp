#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N = 5000+7;
string a[N];
PII w[N][N];
PII b[N][N];
void solve()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    string s;
    cin>>s;
    s=" "+s;
    a[i]=s;
  }
  w[0][0].fi=0;
  w[0][0].se=0;
  b[0][0].fi=0;
  b[0][0].se=0;
  for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=n;j++)
     {
         if(a[i][j]=='.')w[i][j].fi=w[i][j-1].fi+1,w[i][j].se=w[i-1][j].se+1;
         else w[i][j].fi=w[i][j-1].fi,w[i][j].se=w[i-1][j].se;

         if(a[i][j]=='#')b[i][j].fi=b[i][j-1].fi+1,b[i][j].se=b[i-1][j].se+1;
         else b[i][j].fi=b[i][j-1].fi,b[i][j].se=b[i-1][j].se;
     }
  }
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {

    }
  }
    
    
     
}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
   t=1;
//    cin>>t;
   while(t--)solve();

}