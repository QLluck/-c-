#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int P = 998244353;
const int N = 2e5+7;
struct node
{
     int l,r,p;
};
int po(int a,int b)
{
    int res =1;
     while(b)
     {
        if(b&1)res  = res* a %P;
        b>>=1;
        a=a*a%P;
     }
     return res%P;
}
node a[N] ;

int dp[N]={1};
int pix[N]={1};
bool cmp(node a,node b){return a.l<b.l;}
void solve()
{
  int n,m;
  cin>>m>>n;
    for(int i=1;i<=n;i++)pix[i]=1;
  for(int i=1;i<=m;i++)
  {int p,q;
     cin>>a[i].l>>a[i].r>>p>>q;
     a[i].p =  p*po(q,P-2)%P ;
     pix[a[i].l] = (pix[a[i].l]* ((1-a[i].p +P)%P))%P;  ;
  }
  for(int i= 1; i<=n;i++) pix[i]= pix[i]*pix[i-1]%P;
//   for(int i=1;i<=n;i++)
//   {
//     cout<<pix[i]<<' ';
//   }
//   cout<<'\n';
  sort(a+1,a+m+1,cmp);
  for(int i =1;i<=m;i++)
  {int l=a[i].l,r=a[i].r,p=a[i].p;
    int pf = (1ll-p+P)%P;
     int tmp = dp[l-1] * pix[r] %P * po(pix[l-1],P-2) %P * po(pf,P-2)%P * p %P;
     dp[r]= (dp[r]+tmp)%P;
  }
  cout<<dp[n]<<'\n';
}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
   int t;
//    cin>>t;
//    while(t--)
   solve() ;
}