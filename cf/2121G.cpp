#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define int long long
const int N =2e5+7;
int a[N]={0};
int  b[N]={0};
int arr[N]={0};
void solve()
{
  
  int n;
  string s;
  cin>>n;
  cin>>s;
  int it1=-1,it0=-1;
  int ans = 0 ;
  for(int i =0 ;i<s.size() ;i++)
  {
     if(s[i]=='0')
     {  it0 = max(i,it0);
        ans += it0 - it1 ; 
        ans += (it1+1) *2;
     }
     else if(s[i]=='1')
     {
         it1 = max(i,it1);
         ans += it1-it0;
         ans += (it0+1)*2;

     }
     

  }
cout<<ans<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)

    solve();
}