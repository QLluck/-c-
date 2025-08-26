#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;

void solve()
{
  int n,x;
  cin>>n>>x;
  int num = 0;
  int nx = x;
  int f =0;
  int num1=0;

  while(nx)
  { num++;
    if(f&&(!(nx&1)))f=num;
    if(nx&1)num1++;
    nx>>=1;
  }
  if(f==0)f=num+1;
  if(num1>=n)cout<<x<<'\n';
  else 
  {
    int k = n-num1;
    if(num1)
    {   if(num1==1&& k&1)
        {
            if(x==1)cout<<n+3<<'\n';
            else cout<<n+x<<'\n';
        }
        else if(k&1)
        {
           
             cout<<x+k+1<<'\n';
        }
        else cout<<k+x<<'\n';
    }
    else 
    {
        if(n==1)cout<<-1<<'\n';
        else if(n&1)cout<<n+3<<'\n';
        else cout<<n<<'\n';
    }
 
}

}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}