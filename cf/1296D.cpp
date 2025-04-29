#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n ;
const int N =2e5+7;
ll arr[N]={0},it;

ll w[N]={0};
int dp[N]={0};
void solve()
{
  //01背包
  ll n,a,b,k;
  cin>>n>>k>>a>>b;
  ll c = a+b;
  for(int i =1; i<=n;i++)
  {
       ll num;
       cin>>num;
       if(num%c!=0&&num%c<=a)w[i]=0;
       else if(num%c==0)
       {

           w[i]=c/a-1;
           if(c%a)w[i]++;
       }
       else 
       {
           w[i]=(num%c)/a-1;
           if(num%c%a)w[i]++;
       }
      // cout<<num<<' '<<w[i]<<' '<<num%c<<' '<<'\n';
  }
  for(int i =1; i<=n;i++)cout<<w[i]<<' ';
  cout<<'\n';
  sort(w+1,w+n+1);
  int ans =0;
  for(int i =1; i<=n;i++)
  {   k-=w[i];
    if(k<0)break;
       ans++;
  }
  cout<<ans<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}