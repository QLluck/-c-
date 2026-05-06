#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
int a[N];
int b[N];
void solve()
{
    int n,k,m;
    cin>>n>>m;
    int ans1 =0 ;
    int ans2 =0 ;
    int n1 =0 ;
    int n2=0;
    if(n&1)
    {
       if(m&1)
       {
            n1 = ( (n/2) +1)* ((m/2 )+1)  + (n/2)*(m/2);
       }
       else 
       { 
           n1 =  n* (m/2);
       }
    }
    else 
    {
        if(m&1)
        {
            n1 =(n-2)*((m/2)+1);
        }
        else 
        {
            n1=(n-2)*(m/2);
        }
    }
    if(m&1)
    {
        if(n&1)
        {
            n2 = ( (m/2) +1)* ((n/2 )+1)  + (m/2)*(n/2);
        }
        else 
        {
             n2 =  m* (n/2);
        }
    }
    else 
    {
          if(n&1)
        {
            n2 =(m-2)*((n/2)+1);
        }
        else 
        {
            n2=(m-2)*(n/2);
        }
    }
      ans1 = max(n1,ans1);
      ans2 = max(n2,ans2);
      int ans = max(ans1,ans2);
      cout<<ans<<'\n';



    
}
// 2 0
// 2 1
// 
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();

}