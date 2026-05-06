#include<bits/stdc++.h>
using namespace std;
#define int long long 
int gcd(int a,int b)
{
     if(a>b)swap(a,b);
     while(a)
     {
         int tmp = b%a;
         b=a;
         a=tmp;
     }
     return b;
}
void solve()
{
   
   int x,y,a,b;
   cin>>x>>y>>a>>b;
   int gc=gcd(x,y);
    x/=gc;
    y/=gc;
   
   int f =1;
   if( (x%2==1) && (y%2==1) )f=1;
   else f=0;
   x>>=1,y>>=1;
   int ans =0 ;
   while(x||y)
   {
        if( (x%2==1) && (y%2==1) )
        { f=0;
            break;
        }
        else if( (x%2==0) && (y%2==0)) 
        {
            f=0;
            break;
        }
        x>>=1,y>>=1;
        ans++;
   }
   ans+=2;
   if(f)cout<<ans<<'\n';
   else cout<<-1<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // scanf("%lld",&t);
    cin>>t;

    while(t--)
    solve();
}