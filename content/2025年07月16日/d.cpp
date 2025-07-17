#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e3+7;
const int P =998244353;
const int INF = 1e9+7;
ll arr[N]={0};
ll dp[N]={0};
struct node
{
     int l,r;
};
node b[N];
void solve()
{  
      int n,m,c1,c2,c3;
      cin>>n>>m>>c1>>c2>>c3;
      int a = n ;
      int b = m ;
     int ans =0 ;
     if(a>=b)
     {
         ans = (a-b)*c2;
         cout<<ans<<'\n';
         return;

     }
     int it =0 ;
    while(a*2<=b)
    {
        
    }


   
       

    

    

   

    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}