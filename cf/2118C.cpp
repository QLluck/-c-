#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 

const int N = 5000+7;
int a[N];


void solve()
{ 
   int n,k;
   cin>>n>>k;
   int ans =0 ;
   for(int i=1;i<=n;i++)cin>>a[i];
   //int f= 0;
   for(int i= 0;i<=62;i++)
   {  
     for(int j=1;j<=n;j++)
     {
         int sum = (1LL<<i);
        if( (a[j]>>i) &1 )ans++;
        else if(k>=sum)ans++,k-=sum;
       // cout<<i<<' '<<j<<' '<<ans<<'\n';
     }
   }
   cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
// 110
// 110
//1000
//1000