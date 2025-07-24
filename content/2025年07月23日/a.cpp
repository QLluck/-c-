#include<bits/stdc++.h>
using namespace std;
#define int long long
const double pi = 3.1415926535;
int me[64]={0};
int me2[64]={0};
const int P =1e9+7;
void add(int x)
{
    int sum =2;
    for(int i = 32 ; i>=0 ;i--)
    {
         int num = x/sum *(sum/2);
         int yu =  x%sum ;
         if(yu>sum/2)num+= yu-(sum/2);
         me[i]+=num;
         sum*=2;
    }
}
void sub(int x)
{
    int sum =2;
    for(int i = 32 ; i>=0 ;i--)
    {
         int num = x/sum *(sum/2);
         int yu =  x%sum ;
         if(yu>sum/2)num+= yu-(sum/2);
         me[i]-=num;
         sum*=2;
    }
}
void add1(int x)
{
    int sum =2;
    for(int i = 32 ; i>=0 ;i--)
    {
         int num = x/sum *(sum/2);
         int yu =  x%sum ;
         if(yu)num+= min(yu,sum/2);
         me2[i]+=num;
         sum*=2;
    }
}
void sub1(int x)
{
    int sum =2;
    for(int i = 32 ; i>=0 ;i--)
    {
         int num = x/sum *(sum/2);
         int yu =  x%sum ;
         if(yu)num+= min(yu,sum/2);
         me2[i]-=num;
         sum*=2;
    }
}
int po(int a,int b)
{
     int res =1;
     while(b)
     {
         if(b&1)res =a*res %P ;
         b>>=1;
         a=a*a%P;
     }
     return res;
}
void solve()
{
     int l,r,y;
     cin>>l>>r>>y;
   for(int i=0;i<=32;i++)me[i]=0,me2[i]=0;
   add(r+1);
   sub(l);
   add1(r+1);
   sub1(l);
   int sum = r-l+1;
   int ans =0 ;
   for(int i= 32; i>=0 ;i--)
   {
      if(y&1)ans =( ans + me2[i])%P;
      else ans = (ans +me[i])%P;
      y>>=1;
   }
//    for(int i =32 ;i>=0 ;i--)cout<<me[i]<<' ';
//    cout<<'\n';
//    for(int i =32 ;i>=0 ;i--)cout<<me2[i]<<' ';
//    cout<<'\n';
   
   ans =  ans *po(sum,P-2)%P;
   cout<<ans<<'\n';


  
    
    
      
     

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
   while(t--)
    solve();
}