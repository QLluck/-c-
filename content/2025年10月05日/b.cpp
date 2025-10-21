#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
int a[N];
int pix[N]={0};
int me[N];
int f(int x)
{
    int res =0 ;
    while(x)
    {
        res++;
        x>>=1;
    }
    return res-1;
}
void solve()
{
 
  int n,q;
  cin>>n>>q;
  for(int i=0;i<=33;i++)me[i]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    me[f(a[i])]++;
  }
  while(q--)
  {
    int num;
    cin>>num;
    int sum = 0 ;
    int ans =0 ;
  for(int i=33;i>=0;i--)
  {
      int w = (num>>i)&1;
      if(w)sum++;
      ans += min(sum,me[i]);
      sum-=min(sum,me[i]);
    sum<<=1;
  }
  if(sum)cout<<-1<<'\n';
  else cout<<ans<<'\n';
}

   

}
//1 1 1 1 1 8  16 16 16  9
//2  2 1 2 2     
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}