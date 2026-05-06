#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N = 2e5+7;
int a[N];
int t[N];
int lowbit(int x){return x&-x;}
void add(int x,int k)
{
    while(x<N)t[x]+=k,x+=lowbit(x);
}
int query(int x)
{
    int res=0;
    while(x)res+=t[x],x-=lowbit(x);
    return res;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],add(i,a[i]);
    // for(int i=1;i<=n;i++)cout<<query(i)<<' ';
    // cout<<'\n';
    while(m--)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            int x;
            cin>>x;
            add(x,-a[x]+a[x+1]);
            add(x+1,-a[x+1]+a[x]);
            swap(a[x],a[x+1]);
                // for(int i=1;i<=n;i++)cout<<query(i)<<' ';

        }
        else 
        {
            int l,r;
            cin>>l>>r;
            int ans= query(r)-query(l-1);
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
   t=1;
//    cin>>t;
   while(t--)solve();

}