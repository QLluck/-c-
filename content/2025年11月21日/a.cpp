#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
int a[N];
int b[N];

int it;
void solve()
{
  it=0;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  { cin>>a[i];
    if(a[i]==0)
    {
        b[++it]=i;
    }
  }
  b[++it]=n+1;
  int x=0;
int ans = it-1;
  for(int i=1;i<b[1];i++){
    x+=a[i];
    if(x==0){
        ans++;
    }
  }
  for(int i=1;i<=it-1;i++)
  {
    map<int,int>mp;
    int ma= 0 ;
    int sum =0 ;
    mp[0]++;
    for(int j = b[i]+1;j<=b[i+1]-1 ;j++)
    {
        // cout<<j<<' '<<a[i]<<' '<<sum<<'\n';
            sum+=a[j];

            ma=max(mp[sum],ma);
            mp[sum]++;
    }
    ans+=ma;
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