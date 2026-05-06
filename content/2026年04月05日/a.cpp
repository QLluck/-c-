#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
const int mod =998244353;
int a[N];
int sum[N];
int p[N];
void solve()
{
   int n;
   cin>>n;
   priority_queue<int> que;
   for(int i=1;i<=n;i++)cin>>a[i],que.push(a[i]);
   
    while(que.size()>=2)
    {
        int n1 = que.top();
        que.pop();
        int n2= que.top();
        que.pop();
        que.push(n1*n2+1);
    }
    int ma = que.top();
    que.pop();
    for(int i=1;i<=n;i++)que.push(-a[i]);
        while(que.size()>=2)
    {
        int n1 = -que.top();
        que.pop();
        int n2= -que.top();
        que.pop();
        que.push( -(n1*n2+1)) ;
    }
    int mi= -que.top();
    que.pop();
    // cout<<ma<<' '<<mi<<'\n';
    cout<<mi-ma;


    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // te();
    // cin>>t;
    // t=1;
    while(t--)
    solve();
}
