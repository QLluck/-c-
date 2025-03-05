#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
ll arr[N]={0};
int ca(int it ,int x ,int n,string &s )
{
      
       
          if( it >=0&&it<n-3 &&s[it]=='1'&&s[it+1]=='1'&&s[it+2]=='0'&&s[it+3]=='0')return 1 ;
           else  if( it >=1&&it<n-2 &&  s[it-1]=='1'&&s[it]=='1'&&s[it+1]=='0'&&s[it+2]=='0')return 1 ;
            else if(   it >=2&&it<n-1&&  s[it-2]=='1'&&s[it-1]=='1'&&s[it]=='0'&&s[it+1]=='0')return 1 ;
           else  if( it >=3 &&it<n&&s[it-3]=='1'&&s[it-2]=='1'&&s[it-1]=='0'&&s[it]=='0')return 1 ;
           else return 0 ;
          
   
    return 0 ;

}
int xiu(int it,int x,int n,string &s)
{
      int flag1 = ca(it,x,n,s) ;
       s[it]=(char)(x+'0');
       int flag2 = ca(it,x,n,s);
       if(flag1&&flag2)return 0 ;
       else if(flag1==0&&flag2==1) return 1 ;
       else if(flag1==1&&flag2==0)return -1 ;
       else return 0 ;
      
}
void solve()
{
   string s;
   cin>>s ;
   int q;
   cin>>q ;
   int sum = 0 ; 
   int n = s.size();
   for(int i =0 ; i<n-3 ;i++)
   {
      if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')sum++;
   }
   for(int i =1 ;i<=q ;i++)
   {
     int it ,x ;
     cin>>it>>x ;
     it-- ;
     sum += xiu(it,x,n,s);
     //cout<<xiu(it,x,n,s)<<'\n';
     if(sum>=1)
     {
         cout<<"YES"<<'\n';

     }
     else 
     {
         cout<<"NO"<<'\n';
     }
    //cout<<s<<'\n';
     
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