#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e3+7;
#define fi first 
int a[N];

string s[N];
deque<int> que[N];
void solve()
{
   
    
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
{
    for(int j=m;j>=a[i];j--)
    {   
         

       if((j-a[i])!=0 && s[j-a[i]].size()==0)continue;
            if(s[j-a[i]].size()==0&&s[j].size()==0)s[j]=(char)('0'+a[i]);
          else if(s[j].size()==0)s[j]=s[j-a[i]]+(char)('0'+a[i]);
        //   else if(s[j-a[i]].size()==0)s[j]=(char)('0'+a[i]);
          else 
          {
            string s1 = s[j-a[i]]+(char)('0'+a[i]);
            string s2 = s[j];
            int f =0;
            if(s1<=s2)s[j]=s1;
            //  for(int h=0 ;h<s1.size() && h<s2.size();h++)
            //  {
            //     if(s1[h]<s2[h])
            //     { 
            //         f=1;
            //         break;
            //     }
            //  }
            //  if(f==0)
            //  {
            //     f = (s1.size()<s2.size());
            //  }
            //  if(f)s[j]=s1;
          }
    
    }
    
    
    
}
if(s[m].size()==0)cout<<"No Solution"<<'\n';
else 
{
for(int i=0;i<(int)s[m].size();i++)
{
    // if(i==)
    if(i!=(int)s[m].size()-1)
    cout<<(s[m][i]-'0')<<' ';
    else    cout<<(s[m][i]-'0');

}
cout<<'\n';
}
// for(auto p : que[m] )cout<<p<<' ';
// cout<<'\n';
    
 
  

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
    // string s1 ="123";
    // string s2 = "23";
    // cout<<(s1<s2)<<'\n';
    
}