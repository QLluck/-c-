#include<bits/stdc++.h> 

using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N]={0};
int b[N]={0};
int dp[N]={0};
void solve()
{
    for(int i=1;i<=4 ;i++)cin>>a[i];
    int ans =0 ;
    int sum =0 ;
    for(int i=1;i<=4 ;i++)
    {   sum =0;
        
         for(int j=1;j<=a[i];j++)
         {
             cin>>b[i];
             sum+=b[i];
         }
          
         for(int j=1;j<=sum;j++)dp[i]=0;
         dp[0]=1;
         int ma= 0;
         for(int j=1; j<=a[i];j++)
         {
             for(int g = sum/2 ; g>=b[i];g--)
             {
                 if(dp[g-b[i]])
                 {
                    dp[g]=1;
                    ma = max(ma,g);
                 }
             }
         }
         ans += sum -ma ;
    }
    cout<<ans<<'\n';
  
}
signed main( )
{   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
     t =1;
     //cin>>t;
     while(t--)
     solve();
    return 0;
}