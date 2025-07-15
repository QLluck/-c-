#include<bits/stdc++.h>
using namespace std;
const int  N = 2e5+7;
const int INF =1e9+7;
int a[N]={0},it;
#define ll long long

void solve()
{


  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  int flag =0;
  int num =0 ;
  int num1= 0;
  it = 0;
  for(int i =0 ;i<s.size();i++)
  {  
     if(flag==0&&s[i]=='0')
      { 
        if(num1)num1++;
      }
     else if(flag==0&&s[i]=='1')
     {
         if(num1)
         {
             a[++it]=-num1;
             num1=0;
         }
        num++;
        flag=1;
     }
     else if(flag==1&&s[i]=='1')
     { 
        num++;
        
     }
     else if(flag==1&&s[i]=='0')
     {
         flag=0;
         num1++;
         a[++it]=num;
         num=0;
     }
  }
  //cout<<it<<'\n';
  if(s[s.size()-1]=='1')a[++it]=num;
//   for(int i =1; i<=it ;i++)
//   {
//     cout<<a[i]<<' ';
//   }
//   cout<<'\n';
if(it==0)
{
    cout<<0<<'\n';
    return;
}
  if(it==1)
  {
    cout<<n<<'\n';
    return;
  }
  int ans =0 ;
  for(int i =2 ; i<=it ;i+=2)
  {

       int k = -a[i];
       if(n<k*m)ans+=n;
       else ans+=k*m;
  }
  ans+=n;
  cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}