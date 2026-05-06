#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define se second 
#define fi first 
#define PII pair<int,int>

//PGB
//
//123
const int N = 2e6+7;
int a[N];
int b[N];
PII dp[N] ;
PII dp2[N];
void solve()
{
  string s1,s2;
  cin>>s1>>s2;
  int n1= s1.size();
  int n2= s2.size();
  s1="0"+s1;
  s2="0"+s2;
  dp[0].fi=0,dp[0].se=0;
  int mi = 1e9+7;
  int miit =0 ;
  for(int i=1;i<=n2;i++)
  { 
    dp[0].fi=0,dp[0].se=0;
        for(int j=1 ;j<=n1;j++)
        {
            if(s1[j]==s2[i])dp[j].fi=j,dp[j].se=dp2[j-1].se + j-dp2[j-1].fi;
            else dp[j].fi = dp[j-1].fi,dp[j].se=dp[j-1].se;
            if(mi>dp[j].se)
            {
                mi=dp[j].se;
                miit=i;
            }
        }
        for(int j=1;j<=n1;j++)dp2[j].fi=dp[j].fi,dp2[j].se=dp[j].se;
    
  }
 for(int i= miit-mi+1 ;i<=miit;i++)cout<<s1[i];
 cout<<'\n';

 
  

}
//1111122211111
// 1 - 1 - 1
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)solve();
}
// 