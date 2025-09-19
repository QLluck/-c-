#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
int a[N];
int tn[N];
int ts[N];
int lowbit(int x){return x&-x;}
int n,m;
void add(int x,int k,int t[])
{
    while(x<=n)
    {
        t[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x,int t[])
{
    int res=0;
    while(x)
    {
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void solve()
{
   // int n,m;
    cin>>n>>m;
    int ans =0 ;
    for(int i=n;i<=n;i++)ts[i]=0,tn[i]=0;
    for(int i=1;i<=m;i++)
    {
        
        cin>>a[i];
        ans += (query(a[i]+1,tn)*(a[i]+1)-query(a[i]+1,ts) ) *2;
       cout<<a[i]<<' '<<query(a[i],tn)<<' '<<query(a[i],ts)<<'\n';
        add(max(1LL,n-a[i]),max(1LL,n-a[i]),ts);
        add(max(1LL,n-a[i]),1,tn);

    }
    for(int i=1;i<=m;i++)
    {
            add(max(1LL,n-a[i]),-max(1LL,n-a[i]),ts);
        add(max(1LL,n-a[i]),-1,tn);
    }
    cout<<ans<<'\n';
    // 1 2 3 4 5 6
    // a+b >=n; min(a,b) =1  2;
    // +m-1 m
    // 
    // 1//  5 6 
    //      2 4 
    // 1 2 2 4 
    // 2   3 4 5 
     //    2 4 6   
    // 3   3 4 5 6
      //  2  4  6 8 10 11
    // 5  7 8  9 10 11 12 
    // +6 ;
    //        2 4 6 8 10 12
    // 9  1 2 3 4 5 6 7 8 9 10 11
    //        3 +=3 ,
    //        
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
