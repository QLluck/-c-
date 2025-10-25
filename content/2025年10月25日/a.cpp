#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e3+7;
int a[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    int f =0;
    int ans = 0;
    for(int i=1;i<=n;i++)
    { cin>>a[i];
        ans = max(ans,a[i]);
    }
   
    for(int i=1;i<=n-1;i++)
    { 
        int k1 = k ;
        int Max =0 ;
        int shan = a[i+1];
     for(int j=i ;j>=1 ;j--)
     {
        Max = max(Max,a[j]);
         
        if(a[j]<=shan)
        {
            int sum = shan-a[j];
            // cout<<i<<' '<<k1<<' '<<sum<<' '<<shan<<'\n';
            if(k1<=sum)
            {
                shan = a[j]+k1;
                Max = max(Max,shan);
                k1-=k1;
            }
            else 
            {
                shan = shan+1;
                Max = max(Max,shan);
                k1-=sum+1;

            }
           // cout<<i<<' '<<k1<<' '<<sum<<' '<<shan<<'\n';
        } 
        else shan=a[j];
    }
        ans = max(Max,ans);
    }
    cout<<ans<<'\n';


}
// gcd(a,b) * a1 + gcd(a,b)*b1 ;  (a1 + b1 )/gcd(a,b)*b1 ;  a1 / gcd(a,b)*b1   + b1/gcd(a,b);
//
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}