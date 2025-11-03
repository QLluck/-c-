#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 3e5+7;
int a[N];
pii b[N];
int itb;
 int n,k;
  string s;
void solve()
{
   double a = 3.03 ;
  //  double c = 2.02;
   double b = 3.03;
   printf("%.18lf\n %.18lf", a, b);
   a -= 2.02;
   b /= 3;

   if(round(a*1000)>=round(b*100))
   {
     cout << "YES" << endl;
     printf("%.18lf\n %.18lf", a, b);
   }
     else
     {  cout << "NO" << endl;
       printf("%.18lf\n %.18lf", a, b);
     }
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}
