#include<bits/stdc++.h>
using namespace std ;
const int N=1e5+7;
#define ll long long 
ll arr[30]={0}; 


void solve()
{
   ll sum = 0 ; 
    for(int i =1; i<=26 ; i++)
      {  cin>>arr[i];
      sum+=arr[i];
      }
    sort(arr+1,arr+1+26);
    ll ji =0;
    ll o = 0 ; 
    if(sum&1)
    {
ß
    }
    else 
    {
         ji = sum/2 ;
         o = sum/2 ;
         if(ji<arr[26])
         {
            cout<<'0'<<'\n';
            return ;
         }
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