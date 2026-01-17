#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
const int mod = 998244353;
const int INF = 1e18 ;

// #define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
// const int Q=(1<<24)+1;
// char in[Q],*is=in,*it=in,c;
// void read(long long &n){
//   for(n=0;(c=gc())<'0'||c>'9';);
//   for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
// }
int n,m;
int a[N];
int b[N];
void solve()
{
 
cin>>n>>m;
int it =0 ;
 for(int i=1;i<=m;i++)
 {
  cin>>a[i];
 }
 if(m==1)
 {
    cout<<n<<'\n';
    return;
 }
 for(int i=1 ;i<=m;i++)
 {
     if(i==1)
     {
        b[i]+=a[i+1]-a[i]-1;
        b[i]+=n-(a[n]-a[1]+1);
     }
     else if(i==m)
     {
         b[i]+=a[i]-a[i-1]-1;
        b[i]+=n-(a[n]-a[1]+1);
     }
     else 
     {
        b[i]+=
     }
 }

 



}





signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // te();
   
    // read(t);
    t=1;
    // cin>>t;
    while(t--)
    { 
        // flag2=0;
        solve();
        // te();
    }
}