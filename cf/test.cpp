#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e6+7;
int a[N]={0};
int me[N]={0};
int prime[N],it;
int p[N];
void init()
{
  me[0]=1;
  me[1]=1;
  for(int i=2; i<N;i++)
  {
     if(!me[i])prime[++it]=i;
     for(int j =1 ;j<=it;j++)
     {
         if(i*prime[j]>=N)break;
         me[i*prime[j]]=1;
         if(i%prime[j]==0)break;
     }
  }
  for(int i =1;i<=it;i++)p[i]=p[i-1]+prime[i];
}
void solve()
{ 
  int n;
  cin>>n;
  int sum =0 ;
  for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
  {
     if(sum>=p[n-i+1])
     {
      cout<<i-1<<'\n';
      return;
     }
     sum-=a[i];
  }

  

}

signed main() {
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  init();
  //cout<<it<<'\n';
  cin>>t;
  while(t--)
  solve();
}
