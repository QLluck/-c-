#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

void solve()
{
  int n;
  cin>>n;
  int q ;
  cin>>q;
  while(q--)
  {

    string s;
    cin>>s;
    if(s=="-->")
    {
        ll a ,b;
        cin>>a>>b;
        ll sum =1 ;
        while(sum<=b)sum<<=1;
        sum>>=1;
    }

  }

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t ;
    while(t--)
    
   solve();
//    int res =0 ;
//    int sum =1;
   
//    for(int i = 1; i<=7 ; i++)
//    {int flag =0 ;
//        res+=sum;
//        sum*=10 ;
//        for(int j=2 ; j<=sqrt(res); j++)
//        {
//               if(res%j==0)
//               {
//                 cout<<res<<"NO"<<'\n';
//                 flag=1;
//                 break;
//               }
              
//        }
//       if(flag==0) cout<<res<<' '<<"YES"<<'\n';
//    }
}