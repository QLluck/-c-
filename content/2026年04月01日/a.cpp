#include<bits/stdc++.h>
using namespace std;
#define int long long 

int f(int l,int r)
{
    return ((r/2017) - (l-1)/2017);
}
void solve()
{
  int l1,r1,l2,r2;
  while(cin>>l1>>r1>>l2>>r2 )
 {
     int n1 = f(l1,r1);
  int n2 = f(l2,r2);
  int ans = n1*n2 + n1*(r2-l2+1-n2) + n2 *(r1-l1+1-n1);
  cout<<ans<<'\n';
 }
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}