#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII  pair<int,int> 
#define fi first 
#define se second 
const int N = 1e5+7;
int  a[N];
bool f1(int a,int b)
{
    return a>b;
}
void solve()
{
  int n,m;
  cin>>n>>m;
  int sum =0 ;
  for(int i=1;i<=n;i++)
  {
    int n1,n2;
    cin>>n1>>n2;
    sum +=n1;
     a[i]=n2-n1;

  }
  if(n==1)
  {
    cout<<sum+a[1]<<'\n';
    return;
  }
  sort(a+1,a+n+1,f1);
  for(int i=1;i <= m-n && i<=n ;i++)
  {  if(i==n-1)
    { sum = max(sum+a[i]+a[i+1],sum);
        break;
    }
     else if(a[i]>0)sum+=a[i];
  }
  cout<<sum<<'\n';


   
}



signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  t =1;
  cin>>t;
  while(t--)
  solve();
    // te();
}