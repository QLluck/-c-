#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;

pair<int,int> a[N] ;
int dp1[N];
int dp2[N];
int b[N]={0};
void solve()
{
     int n,k;
     cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i,b[i]=a[i].first;
     int yi = a[1].first;
     if(n<=1)
     {
        for(int i=1;i<=n;i++)cout<<b[i]<<' ';
        cout<<'\n';
        return;
     }
     sort(a+1,a+n+1);
     int ma= 0 ;
     int it =0 ;
     if(1==a[n].second)ma = a[n-1].first,it = a[n-1].second;
     else ma = a[n].first,it = a[n].second;
     if(ma!=0)
     {
         cout<<yi+ma<<' ';
         for(int i=2 ;i<=n;i++)
         {
             if(i==it)continue;
             cout<<b[i]<<' ';
         }
         cout<<'\n';
     }
     else 
     {
         for(int i=1;i<=n;i++)cout<<b[i]<<' ';
         cout<<'\n';
     }

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}