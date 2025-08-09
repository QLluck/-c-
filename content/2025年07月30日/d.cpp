#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int P = 1e9+7;
const int N = 2e5+7;
const int INF = 1e18+7;
int a[N]={0};
int p[N]={0};
int b[N],it;
void solve()
{ int n,m;

     scanf("%lld %lld",&n,&m);
    it =0 ;
     int ma = -INF;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),ma = max(ma,a[i]);
    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
   
    int ans2= -INF;
    for(int i= 1; i<=n-m +1;i++)
    {
         int num = p[i+m-1]-p[i-1];
         ans2 =max(num,ans2);
    }
    for(int i=1;i<=n;i++)
    {
         if(a[i]==ma)
         b[++it]=i;
    }
    if( (b[it]-b[1]+1)<=m)
    {  double ans = (double)ans2/m;
          printf("%.8lf\n",ans);
    }
    int l = 1;
    int r= it;
    double ma = (double)(p[b[it]]-p[b[1]-1] ) / (b[it]-b[1]+1);
    
    while(1)
    {
        int flag =0 ;
        if( (b[r]-b[l]+1 )<=m)break;
        int 


    }

    
    



}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    scanf("%lld",&t);
    while(t--)
    solve();
}