#include<bits/stdc++.h>
using namespace std ;
map<int,int>mp;
int arr[10]={0};
int ans ;
int me[10]={0};

void solve()
{
   int x;
   cin>>x;
   int ans=0;
   x=abs(x);
   while(x)
   {
      if(x&1)ans++;
      x>>=1;
   }
   cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}