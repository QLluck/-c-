#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 5e5+7;

// int a[N][N];
PII a[N];
int b[N];
int n,m;
int mi,ma;
PII ans1[N];
int it1=0;
PII ans2[N];
int it2=0;


void solve()
{
  int n;
  cin>>n;
   int ans =0 ;
   if(n==2)
   {
     cout<<0<<'\n';
     return;
   }
   else if(n==3)
   {
    cout<<1<<'\n';
    cout<<1<<' '<<2<<'\n';
    cout<<1<<' '<<3<<'\n';
    return;
   }
   int n1=0,n2=0;
   int x=0,y=0;
   for(int i=2;i<=n;i++)
   {
      for(int j=2;j<=n;j++)
      {
        if(i*j>n)break;
        int num1 = (i-1)*j;
        int num2 = (i)*(j-1);
        int ma = min(num1,num2);
        if(ma>ans)
        {
            ans=ma;
            n1=num1;
            n2=num2;
            x=i,y=j;
        }


      }
   }
   cout<<ans<<'\n';
   int it1=0;
   for(int i=1;i<=y;i++)
   {
    if(it1>=ans)break;
      int s = 1 + (i-1)*x;
      for(int j =s+1 ;j<=s+x-1;j++)
      { 
        if(it1>ans)break;
        it1++;
        cout<<j-1<<' '<<j<<'\n';
      }
   }
   int it2=0;
    for(int i=1;i<=y-1;i++)
   {
    if(it2>ans)break;
      int s = 1 + (i-1)*x;
      for(int j =s ;j<=s+x-1;j++)
      { 
        if(it2>=ans)break;
        it2++;
        cout<<j<<' '<<j+x<<'\n';
      }
   }
   
   
  

//   int ans =0 ;
  
}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
    t=1;
    // cin>>t;
    while(t--)
    solve();
}