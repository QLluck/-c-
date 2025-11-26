#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N];
int prime[N];
int me[N];
int it =0 ;
int ans1[N]={0};
int ans2[N]={0};
void solve()
{
  
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum1= 0 ;
    // for(int i=1;i<=n;i++)
    // {
    //     if(i&1)ans1[i]=1,sum1+=a[i]-1;
    //     else ans1[i]=a[i];
    // }
    // int sum2 =0 ;
    // for(int i=1;i<=n;i++)
    // {
    //     if(i&1)ans2[i]=a[i];
    //     else ans2[i]=1,sum2+=a[i]-1;
    // }
    // if(sum1<=sum2)for(int i=1;i<=n;i++)cout<<ans1[i]<<' ';
    // else for(int i=1;i<=n;i++)cout<<ans2[i]<<' ';
    // cout<<'\n';
//   cout<<sum1<<' '<<sum2<<'\n';
    
}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    // pr();
    // te();
    while(t--)
    solve();
}