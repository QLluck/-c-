#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
int a[N];
int b[N];
int me[N];
pii c[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(a+1,a+n+1);
    int Max= 0 ;
    int sum =0 ;
    int yu =0 ;

    for(int i=1;i<=n;i++)
    {
        sum += a[i];
        int bu = i*a[i] - sum;
        if(bu<=k)Max = max(Max,a[i]);
        else
        {
            bu = (i-1)*a[i-1] - sum + a[i];
            k-=bu;
            yu=k%(i-1);
            k/=(i-1);
            Max+=k;
            // cout<<k<<' '<<Max<<' '<<'\n';
            break;
        }
        if(i==n)
        {
            k-=bu;
            yu=k%n;
            k/=n;
            Max+=k;

        }
    }
    int ans = n*Max -n+1;
    // cout<<Max<<'\n';
   
    int Max1 =0 ;
   int yu1 = yu;
   int sum2= 0;
   for(int i=1;i<=n;i++)
   {
     b[i]-=Max;
    if(b[i]<=0)b[i]=0;
    else sum2++;
   }
//    sum = 0 ;
//    int l = 0 ;
//    for(int i=1;i<=n;i++)
//    {
//     if(b[i])sum++;
//     else if(l<yu)l++;
//     else break;
//         c[l].fi = sum;

//    }
//    sum=0;
//    l=0;
//    for(int i =n ;i>=1 ;i--)
//    {
//     if(b[i])sum++;
//     else if(l<yu)
//     { l++;
//         sum++;
//     }
//     else break;
//         c[l].se = sum;
//    }
//    for(int i=0 ;i<=yu;i++)
//    {
//      cout<<i<<' '<<c[i].fi<<' '<<c[yu-i].se<<'\n';
//    }
//    for(int i=0;i<=yu;i++)
//    {
//     ans = max(ans, ans + min(c[i].fi + c[yu-i].se,n));
//    }
ans += sum2 +yu;
    cout<<ans<<'\n';
   

   
   
   
    


}
// gcd(a,b) * a1 + gcd(a,b)*b1 ;  (a1 + b1 )/gcd(a,b)*b1 ;  a1 / gcd(a,b)*b1   + b1/gcd(a,b);
//
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}