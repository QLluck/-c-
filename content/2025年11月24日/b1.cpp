#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N];
int prime[N];
int me[N];
int it =0 ;

void solve()
{
  
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<int> q1;
    deque<int> q0;
    int it = 0;
  int ans =0 ;
    for(int i=0;i<n;i++)
    {
        //  cout<<s[i]<<' '<<i<<'\n';
        if(s[i]=='1' && (i%2==0) )continue;
        else if(s[i]=='0' &&(i%2==1))continue;
        else if(s[i]=='1') 
        {
            if(q0.size())
            {
                int it0 = q0.back();
                int num = i-it0;
                if(num==1) ans+=1;
                else ans+=2;
                q0.pop_back();
            }
            else q1.push_back(i);
        }
        else 
        {
            if(q1.size())
            {
                int it1 = q1.back();
                int num = i-it1;
                if(num==1) ans+=1;
                else ans+=2;
                q1.pop_back();
            }
            else q0.push_back(i);
        }
    }
    int ans2 =0 ;
    for(int i=0;i<n;i++)
    {
        //  cout<<s[i]<<' '<<i<<'\n';
        if(s[i]=='1' && (i%2==1) )continue;
        else if(s[i]=='0' &&(i%2==0))continue;
        else if(s[i]=='1') 
        {
            if(q0.size())
            {
                int it0 = q0.back();
                int num = i-it0;
                if(num==1) ans2+=1;
                else ans2+=2;
                q0.pop_back();
            }
            else q1.push_back(i);
        }
        else 
        {
            if(q1.size())
            {
                int it1 = q1.back();
                int num = i-it1;
                // cout<<"11111: "<<num<<' '<<it1<<'\n';
                if(num==1) ans2+=1;
                else ans2+=2;
                q1.pop_back();
            }
            else q0.push_back(i);
        }
        // cout<<ans2<<'\n';
    }
ans =min(ans2,ans);
    cout<<ans<<'\n';
    
}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    // pr();
    // te();
    while(t--)
    solve();
}