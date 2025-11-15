#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5+7;

int it =0 ;
int prime[N]={0};
int me[N]={0};
void in()
{
    for(int i=2;i<N;i++)
    {
         if(!me[i])prime[++it]=i;
         for(int j=1;j<=it;j++)
         {
            if(i*prime[j]>=N)break;
            me[i*prime[j]]=1;
            if(i%prime[j]==0)break;
         }
    }
}
int f(int x)
{
 int zh = sqrt(x);
 int it1=1;
 int ans =0 ;
   while(prime[it1]<=zh && prime[it1]<=x )
   {
    while(x%prime[it1]==0)
    {
        x/=prime[it1];
        ans++;

    }
      it1++;
   }
   if(x!=1)ans++;
   return ans;
}
void solve()
{

   int x,y,k;
   cin>>x>>y>>k;
   if(k==1)
   {
      int gc = gcd(x,y);
      if(x==y)cout<<"NO"<<endl;
      else if(gc==x||gc==y  )cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      return ;
   }
   int ma = f(x)+f(y);
   if(k<=ma)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
  
  

 


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    in();
    int t;
    cin>>t;
    while(t--)
    solve();
}
//2 1 3 4
//1 1 1 