#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi  first
#define se second
const int N =1e6+7;
const int INF =1e18+7;

const int P =998244353;

int dp[N]={0};
 void solve()
 {
     int n;
     cin>>n;
     dp[1]=1;
     dp[2]=1;
     int ans =0 ;
     ans = 2;
     int x =2;
     map<int,int>mp;
     for(int i=3 ;i<=n;i++)
     {
        dp[i]= (dp[i-1]+dp[i-2])%x;
        ans +=dp[i];
        ans%=P;
       // if(mp[dp[i]])cout<<"YES"<<'\n';
       // mp[ans]++;
         
        cout<<dp[i]<<' ';
        if(i%3*x==0)cout<<'\n';
        
     }
     cout<<'\n';



 }
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}