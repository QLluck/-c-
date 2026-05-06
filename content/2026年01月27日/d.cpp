#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
int n,m;
const int N= 1e3+7;
int a[N][N];
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)scanf("%lld",&a[i][j]);
    }

    if(n>=3)
    {
        printf("No\n");
        return;
    }
    else if(n==1)
    {
        printf("Yes\n");
        return;
    }
    int sum =0 ;
    for(int i=1;i<=m;i++)
    {
        sum+=abs(a[1][i]-a[2][i]);
    }
    if(sum&1)
    printf("Yes\n");
    else printf("No\n");

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    
     while(scanf("%lld %lld",&n,&m)!=EOF)
    {   
          
          solve();
    
    }
  
}