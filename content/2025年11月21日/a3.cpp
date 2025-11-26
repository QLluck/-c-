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
    
    map<int,int>mp;
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
 
for(int i=n;i>=1;i--)
{
    b[i]=mp[a[i]];
    mp[a[i]]=i;
}
// for(int i=1;i<=n;i++)cout<<b[i]<<' ';
// cout<<'\n';
int it = 1;
int ans =0 ;
while(it<=n)
{
    int s = it;
    int e = b[it];
    if(e==0) 
    {   
        ans++;
        it++;
        continue;
    }
    int num = e-s-1;
    int f = 1;
    for(int i=s+1;i<=e-1;i++)
    {
        if(b[i]==0)
        {
            ans++;
        }
        else 
        {
            int num1 = b[i]-i-1;
            if(num1<=num)
            {
                it=i;
                f=0;
                ans++;
                break;
            }
            ans++;
        }
    }
    if(f==1)it=e+1;
    // cout<<it<<'\n';
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