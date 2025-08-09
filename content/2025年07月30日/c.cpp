#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int P = 1e9+7;
const int N = 2e5+7;
int a[N]={0};
int me[N]={0};

void solve()
{
  int mr = 0 ;
  int ml = 0;
  int ma =0 ;
  int n;
  cin>>n;
  
  for(int i=1;i<=n;i++)
  { cin>>a[i];
    if(a[i]>=ma)
    {
        if(a[i]>ma)
        {
            ml = i ;
            mr  = i;
        }
        else mr = i;
        ma= a[i];
    }
    me[i]=0;

  }
  cout<<ml<< ' '<<mr<<'\n';
  stack<int> sta;
  for(int i=1; i<=ml ;i++)
  {
     while(sta.size() && a[sta.top()] <a[i] )
     {  me[sta.top()]=i;
        sta.pop();
     }
     sta.push(i);
  }
  while(sta.size())sta.pop();
  for(int i=n; i>=mr ;i--)
    {
     while(sta.size() && a[sta.top()] <a[i] )
     {  me[sta.top()]=i;
        sta.pop();
     }
     sta.push(i);
  }
  int ans =0 ;
  int it = 1;
  for(int i=1;i<=n;i++)cout<<me[i]<<' ';
  cout<<'\n';
  while(it<ml)
  {
     int l = it ;
     int r = me[it];
     int num = a[it];
     for(int i= l ;i<r ;i++)
     {
         ans += num-a[i];
     }
     it = r;
    // cout<<it<<'\n';
  }
  it =n;
  while(it>mr)
  {
     int l = it ;
     int r = me[it];
     int num = a[it];
     for(int i= it ;i>r ;i--)
     {
         ans += num-a[i];
     }
     it = r;
    // cout<<'\n';
  }
  for(int i=ml;i<=mr; i++)ans += ma-a[i];
  cout<<ans<<'\n';

  

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}