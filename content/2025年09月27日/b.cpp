#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
pii a[N];
void solve()
{
  int x1,y1,z1,x2,y2,z2;
  cin>>x1>>y1>>z1;
  cin>>x2>>y2>>z2;

  int x3 = y1*z2-z1*y2;
  int y3 = z1*x2-x1*z2;
  int z3 = x1*y2-y1*x2;
  cout<<x3<<' '<<y3<<' '<<z3<<'\n';
  
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}