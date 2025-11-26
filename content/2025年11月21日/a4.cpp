#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
int a[N];
int b[N];

void solve()
{
    
int n;
string s;
cin>>s;
n=s.size();
for(int i=1;i<=n;i++)
{
    // char c;
    // cin>>c;
    a[i]=s[i-1]-'0';
}
// for(int i=1;i<=n;i++)cout<<b[i]<<' ';
// cout<<'\n';
int it = 1;
int ans =0 ;
map<int,int>mp;
for(int i=1;i<=n;i++)
{
    mp[a[i]]++;
    if(mp[a[i]]==2)
    {
        ans+=2;
        mp.clear();
    }
}
 ans =n-ans;
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