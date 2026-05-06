#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e3+7;
#define fi first 
int a[N];

// string s[N];
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
         

       if((j-a[i])!=0 && que[j-a[i]].size()==0)continue;
            if(que[j-a[i]].size()==0&&que[j].size()==0)que[j].push_back(a[i]);
          else if(que[j].size()==0)
          { 
            que[j].clear();
            for(auto p : que[j-a[i]])que[j].push_back(p);
            que[j].push_back(a[i]);
          }
        //   else if(s[j-a[i]].size()==0)s[j]=(char)('0'+a[i]);
          else 
          {
            // string s1 = s[j-a[i]]+(char)('0'+a[i]);
            // string s2 = s[j];
            int f =0;


            for(int h=0;h<min(que[j].size(),que[j-a[i]].size()+1);h++)
            {
                if(h==que[j-a[i]].size())
                {
                     if(a[i]<que[j][h])
                { f=1;
                    break;
                }
                }
                else if(que[j-a[i]][h]<que[j][h])
                { f=1;
                    break;
                }

            }


            if(f)
            { 
                // s[j]=s1;
            que[j].clear();
            for(auto p : que[j-a[i]])que[j].push_back(p);
            que[j].push_back(a[i]);

            }
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
if(que[m].size()==0)cout<<"No Solution"<<'\n';
else 
{
for(int i=0;i<(int)que[m].size();i++)
{
    // if(i==)
    if(i!=(int)que[m].size()-1)
    cout<<(que[m][i])<<' ';
    else    cout<<(que[m][i]);

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