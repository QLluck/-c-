#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int f1(ll a ,ll  x)
{
     while(a||x)
     {
         if( !(a&1)&&(x&1) )return 0;
         x>>=1;
         a>>=1;
     }
     return 1;
}
int f2(ll b , ll y)
{
     while(b||y)
     {
         if( (b&1)&& !(y&1)  )return 0;
         b>>=1;
         y>>=1;
     }
     return 1;
}
void solve()
{
  ll a,b,x,y;
  cin>>a>>b>>x>>y;
  if(a==x&&b==y)
  {
     cout<<"Yes"<<'\n';
  }
  else if(a!=x && b!=y)
  {
     cout<<"No"<<'\n';
  }
  else if(a!=x && b==y)
  {
     if(f1(a,x))
     {
         cout<<"Yes"<<'\n';
     }
     else cout<<"No"<<'\n';
  }
  else if(a==x&& b!=y)
  {
    if(f2(b,y))
    {
        cout<<"Yes"<<'\n';
    }
    else cout<<"No"<<'\n';
  }

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}