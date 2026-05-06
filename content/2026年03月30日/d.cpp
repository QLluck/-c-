#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e6+7;
// pair<int, pair<int ,PII> > a[N];
int ans[N];
int me[N];
int a[N];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
        int len = s.size();
    for(int i=0;i<s.size();i++)a[i+1]= s[i]-'0';
    for(int i=len+1;i<=2*len;i++)a[i]=a[i-n];
    int l,r ;
    l=r=1;
    int ans =0 ;
    // int len = s.size();
    int n1=0,n2=0,n3=0;
    while(r+1<=2*len)
    {

        while(r+1<=2*len && n1<=n && n2<=m && n3<=k )
        {
            if(a[r]==0 && a[r+1] ==0)n1++;
            else if(a[r]==1 && a[r+1]==1)n3++;
            else if(a[r]^a[r+1])n2++;
            ans =max(r-l,ans);
            cout<<l<<' '<<r<<' '<<n1<<' '<<n2<<' '<<n3<<'\n';
            r+=2;
        }
            cout<<l<<' '<<r<<' '<<n1<<' '<<n2<<' '<<n3<<'\n';
            while(l+1<=2*len && l<=r && ( n1>n || n2>m || n3>k) )
            {
            if(a[l]==0 && a[l+1] ==0)n1--;
            else if(a[l]==1 && a[l+1]==1)n3--;
            else if(a[l]^a[l+1])n2--;
             ans =max(r-l,ans);
             cout<<l<<' '<<r<<' '<<n1<<' '<<n2<<' '<<n3<<'\n';
            l+=2;
            }
            // ans = 

    }
    cout<<ans<<'\n';
   

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}