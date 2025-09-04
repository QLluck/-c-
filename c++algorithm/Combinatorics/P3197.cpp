#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =5003;
const int P =100003 ;
 int arr[N]={0};
int po(int a,int b)
{
     int res =1;
     while(b)
     {
         if(b&1)res =res * a %P;
         b>>=1;
         a = a*a %P;
     }
     return res%P;
}
void solve()
{
    int n,m;
    cin>>m>>n;
    
   int ans = (po(m,n)%P - m*po(m-1,n-1)%P +P )%P;
   cout<<ans<<'\n';
}


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
    solve();
   return 0;
}