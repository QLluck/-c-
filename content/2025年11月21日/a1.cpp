#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
int a[N];
int b[N];
int b1[N];
int it;
void solve()
{
  it=0;
  int n;
  cin>>n;
  b[n+1]=0;
  b1[0]=0;
for(int i=1;i<=n;i++)
{ cin>>a[i];
    if(a[i]==0)b1[i]=b1[i-1]+1;
    else b1[i]=b1[i-1];
}
int sum = 0;
// int  =0 ;
map<int,int>mp;
mp[0]++;
int ma= 0;
for(int i=n;i>=1;i--)
{ 
     sum+=a[i];
     mp[sum]++;
     ma=max(mp[sum],ma);
     b[i]=max(ma-1,0LL);
    // cout<<a[i]<<' '<<sum<<'\n';
}
int ans =0 ;
mp.clear();
 ma= 0 ;
 sum =0 ;
for(int i=0;i<=n;i++)
{
    if(a[i]==0)
    {
        mp.clear();
        sum=0;
        ma=0;
        mp[0]++;
    }
    if(i>=1)
    {
    sum+=a[i];
    mp[sum]++;
    ma=max(mp[sum],ma);
    }
  
    ans = max((max(ma-1,0LL))+b[i+1],ans);
}
cout<<ans<<'\n'; 
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();

}