#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>
#define fi first 
#define se second

const int N = 1e5+7;
int a[N];
pii st[N][40];
int gcd(int a,int b)
{
    if(a>b)swap(a,b);
    while(a)
    {
         int temp = b%a;
         b=a;
         a=temp;
    }
    return b;
}

void init(int n)
{
    int k = log(n)/log(2)+1;
    for(int i=1;i<=n;i++)st[i][0].fi=a[i],st[i][0].se=a[i];
    for(int j=1;j<=k;j++)
    {
         for(int i =1;i+((1LL)<<j)-1<=n;i++ )
         {
            st[i][j].fi = gcd(st[i][j-1].fi,st[i+((1LL)<<(j-1))][j-1].fi);
             st[i][j].se = min(st[i][j-1].se,st[i+((1LL)<<(j-1))][j-1].se);
             //cout<<i<<' '<<j<<' '<<st[i][j].fi<<' '<<st[i][j].se<<'\n';
         }
    }

}
int qgcd(int l,int r)
{
     int k = log(r-l+1)/log(2);
    //  cout<<"gcd"<<'\n';
    //  cout<<l<<' '<<r<<'\n';
    //  cout<< st[l][k].fi<<' '<<st[r-(1<<k)+1][k].fi<<'\n';
     int a = st[l][k].fi;
     
    //  cout<<a<<'\n';
      a = gcd(a,st[r-(1LL<<k)+1][k].fi);
    //   cout<<a<<'\n';
           return a;
}
int qmi(int l,int r)
{
         int k = log(r-l+1)/log(2);
        // cout<<"MI"<<'\n';
         //cout<<l<<' '<<r<<'\n';
        //  cout<<st[l][k].se<<' '<<st[r-(1<<k)+1][k].se<<'\n';
          int a = st[l][k].se;
         // cout<<a<<'\n';
          a = min(a,st[r-(1LL<<k)+1][k].se);
        // cout<<a<<'\n';
     return a;
}
int check(int l,int mid)
{
       
     return qgcd(l,mid)==qmi(l,mid);
}
void solve()
{
  int n;
 cin>>n;
 for(int i=1;i<=n;i++)cin>>a[i];
 init(n);
 int ans =n ;
//  for(int i=1;i<=n;i++)
//  {
   
//         for(int j =i;j<=n;j++)
//         {
//             cout<<i<<' '<<j<<' '<<qgcd(i,j)<<'\n';
//         }

    
//  }
 for(int i=1;i<=n;i++)
 {
    int l = i;
    int r = n+1;
    //cout<<"YES"<<'\n';
   // cout<<i<<'\n';
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(check(i,mid))l=mid;
        else r = mid;
       // cout<<l<<' '<<mid<<' '<<check(i,mid)<<' '<<qgcd(i,mid)<<' '<<qmi(i,mid)<<'\n';
    }
    int rm = l ;
    l=i;
    r=n+1;
        while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(check(i,mid))r=mid;
        else l = mid;
       // cout<<l<<' '<<mid<<' '<<check(i,mid)<<' '<<qgcd(i,mid)<<' '<<qmi(i,mid)<<'\n';
    }
  // cout<<l<<'\n';
  int lm = r;

    ans +=rm-lm+1;

 }
cout<<ans<<'\n';
   




 
// cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    cout<<2*3*5*7*11*13*17<<'\n';
    //solve();
}