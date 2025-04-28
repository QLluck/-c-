#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
int arr[N]={0};

void solve()
{
  int n;
  cin>>n;
  ll res=0;
  res=n;
  while(n>=10)
  {
      ll temp = n/10;

      n%=10;
      n+=temp;
      res+=temp;
  }
  cout<<res<<'\n';




}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}