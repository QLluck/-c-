#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second

const int N =100;
const int mod = 1e9+7;
pii me[N];
int it;

int n;
int f(int x)
{
 return (n/x);
}
int fn(int x)
{
    int num = 0;
    while(x)
    {
        num++;
        x/=10;
    }
    return num;
}

void solve()
{
    
    
   
//    int k;
//    int it =1;
   int sum = 1;
   cin>>n;
int ans =0 ;
    for(int i=1;i<=20;i++)
    {
        sum*=i;
    }
    int ans1 =0 ;
   for(int i=20;i>=1;i--)
   {
 
    // sum/=i;
    int n1 = f(me[i].fi)-f(me[i+1].fi);
    // cout<<n1<<' '<<'\n';
  n1%=mod;
    ans+= n1*me[i+1].se ;
    ans%=mod;
    // sum*=i;
   }
   cout<<ans<<'\n';
//    cout<<ans1<<'\n';

 

}

void init()
{
    int sum =1;
    me[++it].fi = 1;
    me[it].se = 1;
 for(int i=2;i<=42;i++)
 {
    sum = sum/gcd(sum,i) *i ;
    if(sum!=me[it].fi)
    {
        me[++it].fi = sum;
        me[it].se =i ;
    }
    // cout<<me[it].fi<<' '<<me[it].se<<' '<<it<<' '<<fn(me[it].fi)<<'\n';
 }
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
       
init();
    int t;
    cin>>t;
    while(t--)
    
    solve();
}