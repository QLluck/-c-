#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N =2e5+7;
int a[N]={0};

void solve()
{
   int n,m,k;
   cin>>n>>m>>k;
//    for(int i=1; i<=n;i++)cin>>a[i];

   int it = 1;
   int mn = 0;
   m = m + 1;
   int num = 0;
   int fu = 0 ;
   while(it<=n)
   {

      if( (it%k==1) ||k==1 )
      {   num = fu;
         mn++;
      }
      if (mn == m + 1)
      {
         fu += k;
         mn = 1;
         num = fu;
      }
      a[it] = num;
      num++;
      it++;
      // cout << num << ' ' << it << ' ' << mn << '\n';
   }

   for(int i =1; i<=n;i++)cout<<a[i]<<' ';


   cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
       { solve();
       }
}