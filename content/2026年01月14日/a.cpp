#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second
const int N = 2e6+7;
int a[N];
int d[N];
int me[N];

void solve()
{
 
   string s;
   int k;
   cin>>k;
   cin>>s;
    int n,m;
    cin>>n>>m;
    int mi = 1e9+7;
    int sum =0 ;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
    }
     int ma = m-n+1 ;
    //  cout<<ma<<'\n';
     ma= ma%k;
     if(s[ma]=='1')cout<<2<<'\n';
     else cout<<1<<'\n';
    //  cout<<s[ma]<<'\n';
 
   

}


signed main()
{  

    ios::sync_with_stdio(0),cout.tie(0),cout.tie(0);
    int t;
    t =1;
    
    cin>>t;
    while(t--)
    solve();
}
// 1
// 2019 5 12 Monday
// 2019 5 12
