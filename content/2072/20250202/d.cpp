#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
ll arr[N]={0};
void solve()
{
   
   int n,x ;
   cin>>n>>x; 
   int flag =0;
   for(int i = 1;  i<=n ;i++)
  {
     cin>>arr[i];
     if(arr[i]==x)flag=1 ;
     
  }
  if(flag)
  {
    cout<<1<<'\n';
    return ;
  }
  sort(arr+1,arr+n+1);
  if(2*arr[n]>=x)
  {
    cout<<2<<'\n';
    return ;
  }
  else 
  {
     ll sum =(ll)x/arr[n];
     if(x%arr[n])sum++;
     cout<<sum<<'\n';
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