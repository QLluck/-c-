#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 5e5+7;
int a[N];
int pix[N];
bool cmp(pii a,pii b)
{
    if(a.fi!=b.fi)return a.fi<b.fi;
    else return a.se<b.se;
}
void solve()
{

 int n;
 cin>>n;
 int ans =n;
 int f =0;
 for(int i=1;i<=n;i++)
 {
    cin>>a[i] ;
    a[i]-=i;
    if(a[i]<0)f=1;
    pix[i]=a[i]+pix[i-1];
 }
 if(f)
 {
    cout<<-1<<'\n';
    return;
 }
 int mi = 1e18+7;
 for(int i=n;i>=1;i--)
{
    if(mi<a[i])ans+=a[i];
    else ans += max(0LL,a[i]-pix[i-1]);
    mi =min(a[i],mi);

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