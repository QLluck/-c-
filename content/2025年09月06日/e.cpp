#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
const int P = 1e9+7;
int a[N]={0};
void solve()
{
   int n,m;
   cin>>n>>m;
   int f = 0 ; 
   for(int i=2;i<=m;i++)
   { cin>>a[i];
    if(a[i]==m+1)f=1;
   }

   if(m+1>n||f)
   { cout<<-1<<'\n';
    return;
   }
   
   int kon = n-m-1;

}


signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

  //for(int i=1;i<=10;i++)cout<<pai[i]<<' '<<'\n';
//   init();
//   cout<<pai[10]<<'\n';
//   int t;
//   cin>>t;
//   while(t--)
//   solve();
// ce();
   cout<<(1<<25)<<'\n';

}