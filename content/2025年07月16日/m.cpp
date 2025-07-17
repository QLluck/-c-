#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e6+7;
const int P =998244353;
ll arr[N]={0};
int check(int x,int d)
{ 
      for(int i =x; i<=x+d; i++)
      {
          for(int j = i+1 ;j<=x+d ;j++)
          {
             for(int k = j+1; j<=x+d;k++)
             {
                 if(arr[i]<=arr[j]&&arr[j]<=arr[k])return 0;
                 if(arr[i]>=arr[j]&&arr[j]>=arr[k])return 0;
                 
             }
          }
      }
      return 1;
}
void solve()
{
     int n;
     cin>>n;
     int ans =0 ;
     for(int i =1;i <=n;i++)cin>>arr[i];
     for(int i=1; i<=n ;i++)
     {  ans++;

        if(i+3<=n&&check(i,3))ans++;
        if(i+2<=n&&check(i,2))ans++;
        if(i+1<=n)ans++;
     }
     cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}