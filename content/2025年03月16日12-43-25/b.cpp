#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;

int arr[N]={0};
int arr2[N]={0},it;
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
     int n,k;
     cin>>n>>k;
  
      int ans = n ;
      while(k>=n)
      {
            if(k==n)
            { cout<<"Bob" <<'\n';
                return ;
            }
            if(k&1)k++;
            k=k/2 -1;

            
      }
      cout<<"Alice"<<'\n';

   
     
}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
  
   cin>>t ;
   while(t--)
   solve();
}