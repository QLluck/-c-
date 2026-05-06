#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
PII a[N];
int prime[N],it;
int me[N];
void pri()
{
     me[2]=0;
    me[1]=0;
    for(int i=2;i<N;i++)
    {
        if(!me[i])prime[++it]=i;
        for(int j=1;j<=it;j++)
        {
            if(i*prime[j]>=N)break;
            me[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void solve()
{
    int k,n;
    cin>>n>>k;
    int cn=0;
    for(int i=1;i<=n;i++)a[i].fi=0,a[i].se=i;
    for(int i=1;i<=n;i++)
    {
        int ans = n/i-1  ;
        int num =i;
        int sum =1;

        if(!me[i])
        {
            if(i==1)a[i].fi=n/i-1;
            else a[i].fi = n/i;
            
            continue;
        }
      
        for(int j=1;j<=2e3;j++)
        {
            cn++;
            if(prime[j]>num)break;
            if(num%prime[j]==0)
            {
                    int cnt =0 ;
                    while(num%prime[j]==0)
                    {
                        // cn++;
                        num/=prime[j];
                        cnt++;
                    }
                    sum*=(cnt+1);
            }
        }
        a[i].fi = sum-1 +ans;
        //  cout<<ans<<'\n';
        //  a[i].fi=ans;
    }
    // a[1].fi=n-1;
    cout<<cn<<"\n";
    // for(int i=1;i<=n;i++)cout<<a[i].fi<<' ';
    sort(a+1,a+n+1);
    // cout<<'\n';
    cout<<a[n-k+1].fi<<'\n';
    
    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    pri();
    t=1;
    cin>>t;
    while(t--)
    solve();
}