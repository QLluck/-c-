#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e3+7;
const ll P =1000000007;
const int INF = 1e9+7;
ll arr[N]={0};

void solve()
{  
     int n;
     cin>>n;
     if(n==0)
     {
         cout<<1<<' '<<0<<'\n';
         return;
     }
     ll a = 1,b=1 ,c=2;
     for(int i=1;i<=n ;i++)
     {
       if(i==n) cout<<a<<' '<<b<<'\n';
        ll a1 = (a*a%P + 2*a%P *b )%P;
        ll b1 =( b*b%P +a*a%P )%P ;
        a =a1;
        b =b1;
         
     }
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}