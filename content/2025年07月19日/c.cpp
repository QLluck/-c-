#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =6e5+7;
int a[N]={0};
int b[N]={0};
int gcd(int a,int b)
{  if(a>b)swap(a,b);
     while(a)
     {
         int temp = b%a;
        b =a;
        a = temp;
     }
     return b;

}
void solve()
{
     int n;
     cin>>n;
     int len = n;
     for(int i =1; i<=n;i++)cin>>a[i];
     int ma =1 ;
    
     for(int i = n-1;i>=1; i-- )
     {
          b[i]= a[i]/gcd(a[i+1],a[i]);
     }
    //  for(int i =1;i<=n;i++)cout<<b[i]<<' ';
    //  cout<<'\n';
     int ans =b[n-1] ;

     for(int i =n-1;i>=1;i--)
     {
         ans = ans/gcd(b[i],ans)*b[i];
        // cout<<' '<<ans<<'\n';
     }
     
    //  for(int i =1;i<=n;i++)cout<<a[i]<<' ';
    //  cout<<'\n';
     cout<<ans<<'\n';


    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}