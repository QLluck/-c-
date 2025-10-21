#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
int a[N]={0};
int dix[N]={0};

void solve()
{
    int n;
    cin>>n;
    int sum = 0;
    int fu = 0;
    int z =0 ;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        dix[i]=a[i]-a[i-1];
        if(dix[i]<0)fu+=abs(dix[i]);
        else z += dix[i];
        sum += abs(dix[i]);
        
    }
    
    int ans = min(abs(a[1] - fu) ,abs(a[n]-z) );
    ans +=sum;
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