#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
int a[N];
int b[N];

void solve()
{
  int n;
  cin>>n;
    int num =0 ;
    int it =0 ;
    for(int i=1;i<=n;i++)
    { 
        cin>>a[i];
        if(a[i]==0)
        { num++;
            if(num==0)it=i;
        }
    }

     map<int,int>mp;
    
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+b[i-1];
        mp[b[i]]++;
    }
    int ans =0 ;
    if(num==0)
    {
       cout<<mp[0]<<'\n';
       return ;        
     
    }
    map<int,int>me;
    for(int i=1;i<=it;i++)
    {
        if(a[i]!=0)me[a[i]]++;
    }
    for(auto p : mp)
    {
        if(p.fi)
    }
    

cout<<ans<<'\n'; 
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();

}