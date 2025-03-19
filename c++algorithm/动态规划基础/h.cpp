#include<bits/stdc++.h>
const int N =4e3+7 ;
int dp[N] ={0};
int arr[3]={0} ;
int me[N]={0} ;
void solve() 
{
     int n,a,b,c;
     std::cin>>n>>arr[0]>>arr[1]>>arr[2] ;
     std::sort(arr,arr+3) ;
     dp[arr[0]] =1 ;
     dp[arr[1]] =1 ;
     dp[arr[2]] =1 ;
     for(int i = 0 ; i< 3;i++)
     {if(!me[arr[i]])
      {  me[arr[i]]=1 ;
       
        for(int j= arr[i] ; j <=n ; j++)
          if(dp[j-arr[i]])
           dp[j]=std:: max(dp[j-arr[i]] + 1 ,dp[j]);
      }

     }
   
  

    std::cout<<dp[n]<<'\n' ;
       
     

}

int main()
{
    std::ios::sync_with_stdio(0),std::cout.tie(0),std::cin.tie(0) ;
    solve() ;
}