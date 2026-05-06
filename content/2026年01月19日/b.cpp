#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{
   
   int n;
   cin>>n;
   
    if(n==1)
   { cout<<1<<'\n';
    cout<<1<<'\n';
   }
    
   else if(n==2)    
   {
    cout<<2<<'\n';
    cout<<2<<' '<<2<<'\n';
   }
   else if(n==3)
   {
    cout<<2<<'\n';
     cout<<2<<' '<<2<<'\n';
   }
   else if(n>=4)
   {
    int ans=  2*(n-2);
    cout<<ans<<'\n';
   // cout<<2<<' '<<2<<' ';
    for(int i=2 ;i<=n-1 ;i++)cout<<i<<' ';
    // cout<<n-1<<' '<<n-1<<' ';
    for(int i =n-1;i>=2;i--)cout<<i<<' ';
    cout<<'\n';
   }
  

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // scanf("%lld",&t);
    // cin>>t;

    while(t--)
    solve();
}