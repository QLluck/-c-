#include<bits/stdc++.h>

const int N = 5e5+7 ;

int dp[N]= {0};
int h[N]= {0} ;
int hn[N]={0} ;
int pos;


void solve()
{
    int n;
   std::cin>> n;
   for(int i =1; i<=n ;i++)
   {
       int a,b,c;int k =1 ;
       std::cin>>a>>b>>c ;
       while(k<=c)
       {   
          h[++pos] = a*k ;
          hn[pos]= b ;
           c-=k;
           k*=2;
       }
       if(c)
       {
           h[++pos] = a*c ;
           hn[pos] = b ;
       }

   }
   int ans = 0 ;
   for(int i = 1 ;i<=n ;i++)
   {   
      
   }


}
int mian()
{
      std::ios::sync_with_stdio(0),std::cout.tie(0),std::cin.tie(0);
      solve();
}