#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define int long long
const int N =2e5+7;
int a[N]={0};
int  b[N]={0};
int arr[N]={0};
void solve()
{
  
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)cin>>b[i];
    for(int i =1;i<=n;i++)
    {
     arr[i]= a[i]/gcd(a[i],b[i])*b[i];
    }

    int l = 0 ;
      for(int i =1;i<=n;i++)
      {
           cout<<arr[i]<<' ';
      }
      cout<<'\n';
    for(int i =1;i<=n;i++)
    {
        l = gcd(l,arr[i]);
        if(l!=a[i])
        {
          cout<<"NO"<<'\n';
          
          return;
        }
    }
    l=0;
    for(int i= n; i>=1 ;i--)
    {     l = gcd(l,arr[i]);
        if(l!=b[i])
        {
          cout<<"NO"<<'\n';
          return;
        }
    }
        

     cout<<"YES"<<'\n';
     


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)

    solve();
}