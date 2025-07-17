#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e6+7;
const ll P =998244353;
 int arr[N]={0};
ll dp[5007][5007]={0};

ll po(ll a ,ll b)
{
     ll res= 1 ;
    while(b)
    {  if(b&1)res = res*a %P;
         b>>=1;
        a=a*a%P;
    }
    return res%P;
 }
void init()
{
     for(int i =0; i<=5003;i++)dp[i][i]=1;
     for(int i = 1 ;i<=5003 ;i++)dp[i][0]=1;
    for(int i =1; i<=5003 ;i++)
    {
         for(int j =1;j <i ;j++)
         {       

             dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) %P;
             dp[i][i-j]=dp[i][j];
         }
    }
}
void solve()
{  ll n,m;
    scanf("%lld %lld",&n,&m);

    if(m>n)
    {
        printf("%lld",0LL);
        return;
    }
    
    ll ans = po(m,n)%P ;
    ll shen = n-m;
    for(int i =1 ;i<m ;i++)

    {
      ans = (ans- (po(i,n)*dp[m][i]) %P +P)%P ;
      cout<< po(i,n)<<' '<<dp[m][i]<<'\n';
    }
   
     
    printf("%lld",ans);

    
    
}
int main()
{
  //  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  init();
    solve();
   return 0;
}