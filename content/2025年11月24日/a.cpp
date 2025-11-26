#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N];
int prime[N];
int me[N];
int it =0 ;

void solve()
{
  
    int n;
    cin>>n;
    int sum= 0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
     sum = n/2;
     int num;
    if(n&1)
    { sum+=1;
        num=a[sum];
    }
    else 
    {
         num = (a[sum+1] + a[sum])/2;
    }
    for(int i=1;i<=n;i++)cout<<num<<' ';
    cout<<'\n';
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