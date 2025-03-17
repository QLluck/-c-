#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;

int arr[N]={0};
int arr2[N]={0},it;
int arr3[N]={0},it2;
int gcd(int a ,int b)
{
      if(a>b)swap(a,b);
       while(a)
       {
           int temp = b%a;
           b =a ;
           a=temp ;
       }
       return b ;
}
void solve()
{ 
     int n;
     cin>>n;
     it = 0;
     for(int i = 1; i<=n ;i++)
     {
          cin>>arr[i];
         if(arr[i]!=i)arr2[++it]=i;
     }
     for(int i =2; i<=it ;i++)
     {
         arr3[i]=arr2[i]-arr2[i-1];
     }
     sort(arr3+2,arr3+1+it);
 
      int ans = arr3[2];
      for(int i =2; i<=it ;i++)
      {
         if( arr3[i]%ans!=0)ans=gcd(ans,arr3[i]);
      }
    
     
    
     cout<<ans<<'\n';
}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
  
   cin>>t ;
   while(t--)
   solve();
}