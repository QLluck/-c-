#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
ll arr[N]={0};
void solve()
{
   int n;
   cin>>n; 
   ll sum = 0 ;
   for(int i =1 ; i<=n ; i++)
   {
     cin>>arr[i];
     sum+=arr[i];
   }
   double avg= (double)sum/n /2 ;
   sort(arr+1,arr+n+1);
   if(n<=2)
   {
     cout<<-1<<'\n';
   }
   else 
   {
     if(n&1)
     {
          int it = n/2 +1 ;
          double x = (double)arr[it] *2*n - sum ;
          cout<<x<<'\n';

     }
     else 
     {
          int it = n/2 +1 ;
          double x = (double)arr[it] *2*n - sum ;
          cout<<x<<'\n';

     }
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
