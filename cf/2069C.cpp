#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 3e5+7;
const int mod = 998244353;
int a[N];

void solve()
{
    int n;
    cin>>n;
    int ans =0 ;
    int sum =0 ;
    int n1 =0 ;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)n1+=1;
        else if(a[i]==2)
        {
            sum*=2;
            sum%=mod;
            sum+=n1;
            sum%=mod;
        }
        else if(a[i]==3)
        {
            ans+=sum;
            ans%=mod;
        }
    }
    cout<<ans<<'\n';
    

}

 //BRBRB
 //BBBRB
 //BRBBB
 //BRBRBRB
 //5 3 
 //5 4
 // 1 2 3 4 5
 //2 4  8
 //8 100 3 2 7
 //1000 999 1000 1 2
 // 1 2 3 4 
 // 3 2 1 2 2 1 3
 // 0 0 0 1 
 // 0 0 0 1 1 0 5
    

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
