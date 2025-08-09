#include<bits/stdc++.h> 

using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N]={0};
void solve()
{
     string s;
     cin>>s;
     int n =s.size();
       s = '0' +s;
      stack<int> sta;
       for(int i=1;i<=n;i++)
       { sta.push(i);
            while(sta.size()>=2)
            {
                int i1 = sta.top();
                sta.pop();
                int i2= sta.top();
                sta.pop();
                if(s[i2]=='('&&s[i1]==')')continue;
                else 
                {  sta.push(i2);
                sta.push(i1);
                     break;
                }
            }
       }
        n=  sta.size();
    for(int i=n;i>=1;i--)
    {
         a[i] = sta.top();
         sta.pop();
    }
    int ans =0 ;
    int sum =0 ;
    for(int i =1 ,j = n/2+1; j<=n;j++,i++)
    {
          ans += a[j]-a[i] -sum ;
          sum+=1;
         // cout<<a[j]<<' '<<a[i]<<'\n';
    }
    cout<<ans<<'\n';
}
signed main( )
{   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
cin>>t;
while(t--)
solve();
    return 0;
}