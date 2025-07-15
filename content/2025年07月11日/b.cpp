#include<bits/stdc++.h>
using namespace std;
const int  N = 2e5+7;
const int INF =1e9+7;
int a[N]={0};
int b[N]={0};
#define ll long long
  int n;


void solve()
{
 
int n;
cin>>n;
map<int,int >mp;
int it  = 4*n-2;
for(int i =1 ;i<=n;i++)
{
   while(mp[it])it-=2;
   
   for(int j = it ;j >=1 ;j--)
   {
      if(it%j==0)mp[j]++;
   }
    
  
   cout<<it<<' ';
}
cout<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}