#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
const ll P= 998244353;
int arr[N]={0};
int b[N]={0},it;
priority_queue<int> que;
ll poww(ll n,ll m)
{
      ll res= 1;
      while(m)
      {
          if(m&1) res = res *n%P;
          m>>=1;
          n=n*n%P;
      }
      return res%P;
}
void solve()
{
  int n;
  cin>>n;
  int flag = 0 ;
  ll m=1;
  ll num =1  ;
  map<ll,ll>mp;
  b[0]=0;
  for(int i=1; i<=2*n ;i++)
  {
     ll  a;
     cin>>a;

     if(a>=0)
     {
         mp[a]++;
         que.push(-a);

     }
     else 
     {
         ll temp = -que.top();
         m=m*mp[temp]%P;
         mp[temp]--;
         num =num*que.size()%P;
         que.pop();
         b[++it]=temp;


     }
     if(b[it]<b[it-1])flag=1;
  }
  if(flag)
  {
      cout<<0<<'\n';
      return;
  }
  ll ans = m%P*poww(num,P-2)%P;
  cout<<ans<<'\n';



}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
 
    solve();
  
}