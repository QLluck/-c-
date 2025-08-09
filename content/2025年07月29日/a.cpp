#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
int a[N]={0};
int me[40][2][2] ={0};
void solve()
{    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i =1; i<=n;i++)
    {    int ji = 0;
          for(int j=0 ;j<=31 ;j++)
          {
             int num = (a[i]>>j)&1;
             me[j][num][ji]++;
             if(num&1) ji= !ji;
          }
    }

    
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {    int ji =0 ;
         for(int j =0;j<=31;j++)
         {
             int num = (a[i]>>j)&1;
             
             ans += (1LL<<j)*me[j][!num][ji];

             if(num&1) ji= !ji;
         }
    }
    cout<<ans/2<<'\n';


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}