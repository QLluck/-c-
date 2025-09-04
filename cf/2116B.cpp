#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 
const int mod =998244353;
const int N = 1e5+7;
int q[N];
int p[N];
pii a[N];
pii ma[3][N];
int po(int a,int b)
{
    int res= 1;
    while(b)
    {
        if(b&1) res =res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
void solve()
{ 
   int n,k;
   cin>>n;
   ma[1][0].fi=-1;
   ma[2][0].fi=-1;
   ma[1][0].se=-1;
   ma[2][0].se=-1;

   for(int i=1;i<=n;i++)
    { cin>>p[i];
        if(p[i]>ma[1][i-1].fi)ma[1][i].fi=p[i],ma[1][i].se=i;
        else ma[1][i]=ma[1][i-1];
   }
   for(int i=1;i<=n;i++)
   { cin>>q[i];
      if(q[i]>ma[2][i-1].fi)ma[2][i].fi=q[i],ma[2][i].se=i;
        else ma[2][i]=ma[2][i-1];
   }
//    for(int i=1;i<=n;i++)cout<<ma[1][i].fi<<' ';
//    cout<<'\n';
//    for(int i=1;i<=n;i++)cout<<ma[2][i].fi<<' ';
//    cout<<'\n';
   for(int i=1;i<=n;i++)
   {   int ma12,ma22;
    ma12 = q[(i+1)-ma[1][i].se];
    ma22=  p[(i+1)-ma[2][i].se] ;
        if(ma[1][i].fi>ma[2][i].fi)
        {
            a[i].fi=ma[1][i].fi;
            a[i].se =q[(i+1)-ma[1][i].se];
        }
        else if(ma[1][i].fi<ma[2][i].fi)
        {
            a[i].fi=ma[2][i].fi;
            a[i].se =p[(i+1)-ma[2][i].se] ;
        }
        else 
        {
            if(ma12>ma22)
            {
                 a[i].fi =ma[1][i].fi;
                 a[i].se=ma12;
            }
            else 
            {
                 a[i].fi =ma[2][i].fi;
                 a[i].se=ma22;
            }
        }
   }
//    for(int i=1;i<=n;i++)
//    {
//      cout<<a[i].fi<<' '<<a[i].se<<'\n';
//    }
   for(int i=1;i<=n;i++)
   {
       int ans = (po(2,a[i].fi)%mod + po(2,a[i].se)%mod )%mod;
       cout<<ans<<' ';
   }
   cout<<'\n';
   
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
// 110
// 110
//1000
//1000