#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
const int mod = 1e9+7 ;
int a[N];
pii b[N];
bool cmp(pii a,pii b)
{
    int a1 = a.fi-a.se;
    int b1 = b.fi-b.se;
 return a1<b1;
//    else return a.se>b.se;
}
int po(int a,int b)
{
    a%=mod;
    int res =1;
    while(b)
    {
         if(b&1)res =res*a%mod;
         b>>=1;
         a=a*a%mod;
    }
    return res;
}
void solve()
{


 int n,k;
 cin>>n;
    int sum = n*(n+1)%mod *(2*n+1)%mod*po(6,mod-2)%mod;
    int sum2 = ((sum - 1 +mod )%mod -((2+n)*(n-1)%mod*po(2,mod-2)%mod) +mod );
    sum +=sum2;
    sum%=mod;
    sum*=2022;
    sum%=mod;
    cout<<sum<<'\n';


 
}
//100 i
//8
//1
//3
//12
//7
//-3
//2
//12 8 7 3 2 1 -3
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int sum = 1000000000;
    //  sum = sum*sum;
 
    // cout<<sum+1<<'\n';
    // cout<<N<<'\n';
    int t;
    cin>>t;
    while(t--)
    solve();
}