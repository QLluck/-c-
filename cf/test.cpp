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
int check(int mid)
{
   int cnt =0 ;
   char la ='R';
   for(int i=1;i<=n;i++)
   {
    if(a[i]>mid)
    {
    if(s[i]=='B'&&la!='B')
    {
      cnt++;
    }
    la=s[i];
  }
   }
   return cnt<=k;
}
void solve()
{itb=0;
 cin>>n>>k;

 cin>>s ;
 s = '*' +s;
//  while(si<=n&&s[si]=='R')si++;
 for(int i=1;i<=n;i++)
 {
     cin>>a[i];
 }
 int l =-1;
 int r = 1e9+7;
 while(l+1<r)
 {
  int mid =(l+r)>>1;
  if(check(mid))r=mid;
  else l = mid;
 }
//  cout<<'\n';
// cout<<endl<<'\n';
 cout<<r<<'\n';

 //BRBRB
 //BBBRB
 //BRBBB
 //BRBRBRB
 //5 3 
 //5 4
 // 1 2 3 4 5
 //2 4  8
 //8 100 3 2 7
 //1000 999 1000 1 2
 // 1 2 3 4 
 // 3 2 1 2 2 1 3
 // 3 2 1 2 2 0 
 // 0 0 0 1 1 0 5
    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
