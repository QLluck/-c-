#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =5e6+7;
const int P =998244353;
const int INF = 1e9+7;
ll arr[N]={0};
ll dp[N]={0};
ll dp2[N]={0};
struct node
{
     int l,r;
};
node b[N];
void solve()
{   int n;
    cin>>n;
    for(int i = 1; i<=n;i++)
    {
         cin>>arr[i];
         b[i].l=i;
         b[i].r=i;
    }
    int it =0 ;
    int ma = -INF ;
    dp[1]=arr[1];
    it =1 ;
    ma = arr[1];

    for(int i =2; i<=n;i++)
    {
         if(arr[i]>=dp[i-1] + arr[i])
         {
            dp[i]=arr[i];

         }
         e
        
           dp[i] = dp[i-1]+arr[i];



         
    }
    //  for(int i =1; i<=n;i++)cout<<dp[i]<<' ';
    // cout<<'\n';


 

         ans = max(dp[it]+ma,dp[it]-mi);
     
    cout<<ans<<'\n';
    

    

   

    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}