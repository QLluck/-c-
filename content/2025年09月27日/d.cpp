#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
const int mod = 998244353 ;
int a[N];


void solve()
{


 int n;
 cin>>n;

 int n1= n ;
//   if(n1<=4)
//  {
//     if(n1==2)cout<<1<<' '<<2<<'\n';
//     else if(n1==3)cout<<1<<' '<<2<<' '<<3<<'\n';
//     else if(n1==4)cout<<2<<' '<<4<<' '<<1<<' '<<3<<'\n';
//     return;
//  }



//  cout<<sum<<'\n';
int sum = n/2;


if(n&1)
{   sum = (n+1) /2;
    cout<<sum<<' ';
    for(int i=1;i<=n/2;i++)
    {
        cout<<i <<' '<<i+sum<<' ';
    }
    cout<<'\n';

    
}
else 
{
    sum = n /2;
   cout<<sum<<' ';
   cout<<n<<' ';
   n--;
// sum = (n+1) /2;
    // cout<<sum<<' ';
    for(int i=1;i<=n/2;i++)
    {
        cout<<i <<' '<<i+sum<<' ';
    }
    cout<<'\n';
}

 


 


}
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