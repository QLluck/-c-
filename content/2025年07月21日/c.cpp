#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+7;
int a[N]={0};
int b[N]={0};
void solve()
{
       int n;
       cin>>n;
   int p1,p2 ,q1,q2;
   cin>>p1>>p2>>q1>>q2;
   for(int i =1;i<=n;i++)cin>>a[i];
   int mi = a[1];
   int ma = a[1];
   for(int i =2; i<=n;i++)
   {
       if(ma>=a[i])
       {
        mi = max(0LL,mi-a[i]);
       }
       else mi = abs(ma-a[i]);
       ma = ma +a[i];
       //cout<<mi<<' '<<ma<<'\n';
   }
   //cout<<p1<<' '<<q1<<' '<<
   int ans = abs(q1-p1)*abs(q1-p1) +  abs(q2-p2)*abs(q2-p2);
  // cout<<ans<<' '<<mi<<' '<<ma<<'\n';
   if(mi*mi<=ans&&ans<=ma*ma)
   {
    cout<<"YES"<<'\n';

   }
   else cout<<"NO"<<'\n';

    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}