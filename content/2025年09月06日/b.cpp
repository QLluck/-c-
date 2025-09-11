#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
const int P = 1e9+7;
int t[N]={0};
int a[N]={0};
int b[N]={0};
int jie[N]={0};
void init()
{  jie[0]=1;
    for(int i=1;i<N;i++)
    {
        jie[i]=jie[i-1]*i;
        jie[i]%=P;
    }
}
int lowbit(int x){return x&-x;};
void add(int x,int k)
{
     while(x<N)t[x]+=k,x+=lowbit(x);
}
int   query(int x)
{
    int res=0;
    while(x)
    {
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
 int n;
 int ans =0 ;
int dfs(int i,int a[])
{
    if(i==n)
    {add(a[i],-1);
        return 1;
    }
  int q = query(a[i]);
  add(a[i],-1);
  return (dfs(i+1,a)%P+(q-1)*jie[n-i]%P)%P;

}
void solve()
{
  
   
    cin>>n;
    ans =0 ;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=n;i>=1;i--)add(a[i],1);
    ans+=dfs(1,a);
    ans%=P;
    for(int i=n;i>=1;i--)add(b[i],1);
   
    ans+=dfs(1,b);
     ans%=P;
    cout<<ans<<'\n';

    

}
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
//
void test()
{
   // int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)add(a[i],1);
    cout<<dfs(1,a)<<'\n';

}
signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

  //for(int i=1;i<=10;i++)cout<<pai[i]<<' '<<'\n';
  init();
  int t;
  cin>>t;
  while(t--)
  test();
// ce();
//
}
// 1 2 
// 1 2
// 1 3
// 1 3
// 1 4
// 1 4
