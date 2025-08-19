#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
int a[N];
int pix[N]={0};
void solve()
{
string s;
cin>>s;
int it =0 ;

  while(it<s.size()&&s[it]=='0')
  { it++;
  }
  int it0 =it;
  int len1 =0 ;
  int it1 =0 ;
  for(int i= it ;i<s.size();i++)
  {   it1=i;
    if(s[i]=='1')len1++;
    else 
    { 
        break;
    }
  }
  int len0 =0 ;
  for(int i= it1 ;i<s.size();i++)
  {
    if(s[i]=='0')len0++;
    else 
    { 
        break;
    }
  }
  
  int r =  it1-min(len0,len1) +1 ;
  int len2 = 0;
  // len2 = s.size()-it1+1;
   if(len0==0||len1==0)
  {
    cout<<1<<' '<<s.size()<<' '<<1<<' '<<1<<'\n';
    return;
  }
   len2 = s.size()-it1;

  if(r<=s.size())
  {
     cout<<1<<' '<<s.size()<<' '<<r<<' '<<r+len2-1<<'\n';
  }
  else 
  {   
     cout<<1<<' '<<s.size()<<' '<<1<<' '<<1<<'\n';
      
  }
    
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
//1110011
//111010000
//   111010000