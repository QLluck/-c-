#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 1e6+7;
int n,m,k;
void solve()
{ int n;
    cin>>n;
    int num =0 ;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
             cout<<i<<' '<<'\n';
        }
    }

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}