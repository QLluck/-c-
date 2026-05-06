#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N =1e3+7 ;
int  a[N][N];
PII b[N];
int c[N];
int ans= 0;
void solve()
{  
    int n,k,m,a,b;
    // cin>>n>>k>>m>>a>>b;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cout<<i<<' '<<n*k+i <<' '<<n<<' '<<(n*k+i)/k<<'\n';
    }



    
   
   

}
// g,
// gi ti ui
//0 m 2*m
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t =1;
    // cin>>t;
    while(t--)solve();
}