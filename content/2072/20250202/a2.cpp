#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 


struct node
{
     int l ,r ;
     int n ;
};
node  arr[N];
int it ;
bool f(node a ,node b)
{
     return a.n<b.n ;
}
void solve()
{
  int n,k ;
  cin>>k ;
  string s1;
  cin>>s1 ;

  n=s1.size();
  string s ;
  for(int g =0  ; g<=n ;g++)
  {   k = g;
  s= s1; 
    cout<<"k为"<<k<<'\n';
int   flag =0 ;
int l = -1 ; 
it =0;
int num1 = 0 ; 
for(int i =0 ; i<n;i++)
{    
      if(flag&&s[i]=='L') 
      {  num1++;
      }
      else if(flag&&s[i]=='W')
      { 
         arr[++it].n = num1 ;
         arr[it].l =l ;
         arr[it].r=i ;
         l = i ;
         
         num1=0 ;
     
           
      }
      else if(flag==0&&s[i]=='W')
      {
          l = i ;
          
          flag =1 ;
      }
  

}
int r =-1;

if(it)
{
  l = arr[1].l ;
r = arr[it].r ;

}
if(it==0&&flag==1)
{
      r =l ;
}
  sort(arr+1,arr+it+1,f);

// for(int i =1 ;i<=it ;i++)
// {
//      cout<<i<<' '<<arr[i].l<<' '<<arr[i].r<<' '<<arr[i].n<<'\n';
// }
for(int i =1 ;i<=it ;i++)
{
     if(k<=0)break; 
     for(int j = arr[i].l+1 ; j<arr[i].r ;j++)
     {
          if(k<=0)break ;
          k-- ;
          s[j]='W';
     }
}
 for(int i = (r==-1? 0:r+1 ); i<n ;i++)
 {
      if(k<=0)break ;
      s[i]='W';
      k-- ;
 }
 for(int i =(l==-1?-1:l-1) ; i>=0 ;i--)
 {
      if(k<=0)break ;
      s[i]='W';
      k-- ;
     // cout<<i<<'\n';
 }
 //cout<<s<<'\n';
 int ans = 0 ; 
 int flag2 =0 ; 
 for(int i=0 ; i<n ;i++)
 {
      if(flag2&&s[i]=='W')ans+=2 ;
      else if(flag2==0&&s[i]=='W')
      {
          flag2= 1 ;
          ans+=1 ;
      }
      else 
      {
         flag2 =0 ;
      }
 }
 cout<<s<<'\n';
 cout<<ans<<'\n';
  }



     


}
int main()
{
      ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
      int t;
      cin>>t ;
      while(t--)
      solve();
}