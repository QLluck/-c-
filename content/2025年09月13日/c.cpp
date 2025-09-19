#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>
#define fi first 
#define se second

const int N = 1e5+7;
int a[N];



void solve()
{

  int x0,y0,x1,y1,x2,y2;
  cin>>x0>>y0>>x1>>y1>>x2>>y2;
  if(x1>x2)
  {
    swap(x1,x2);
    swap(y1,y2);
  }
  else if(x1==x2)
  {
     if(y1>y2)swap(y1,y2);
  }

  if(x1<=x0&&x0<=x2 && x1!=x2)
  {
    cout<<x0<<' '<<y0<<'\n';
    return;
  }
  if(x1<=x0&&x0<=x2&&x1==x2)
  {
      
  }

 
// cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    // cout<<2*3*5*7*11*13*17<<'\n';
    solve();
}