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
    while(it<n)
    {
        while(it<n && (s[it]=='1') )
        {
            if( !(it&1) )q1.push_back(it);
            it++;
        }
        while(it<n &&(s[it]=='0'))
        {
            if(it&1)q0.push_back(it);
            it++;
        }
          
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(s[i]=='1' && (i&1) )continue;
    //     else if(s[i]=='0' &&(i%2==0))continue;
    //     else if(s[i]=='1') q1.push(s[i]);
    //     else 
    //     {

    //     }
    // }
    
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