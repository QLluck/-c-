#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N =5003;
int P ;
int po(int a,int b)
{   int res= 1;
     while(b)
     {
         if(b&1)  res=  res*a%P;
         b>>=1;
         a=a*a%P;
     } 
     return res;
}

void solve()
{
   int f,n,m;
   cin>>f>>n>>m>>P;
   int ans =1;
   for(int i= n -m+1; i>= n - 2*m +2 ;i--)ans = ans *i %P ;
   cout<<ans<<'\n';
    

}


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
    solve();
   return 0;
}