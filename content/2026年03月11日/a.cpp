#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N =5e5+7 ;
PII a[N];
PII b[N];
int c[N];
bool f1(PII a,PII b)
{
    if( a.fi == b.fi )return a.se<b.se;
    else return a.fi<b.fi;
}
int n;
bool check(int mid)
{
    int it =0 ;
    // cout<<mid<<'\n';
    priority_queue<int> que;
    for(int i=1;i<=n;i++)
    {
        if(a[i].fi<mid)c[++it]=a[i].se;
        else 
        { que.push(-(a[i].se + a[i].fi-mid));
            // cout<< a[i].se + a[i].fi-mid <<' ';
        }
    }
    // cout<<'\n';
    sort(c+1,c+it+1);
    // for(int i=1;i<=it;i++)cout<<c[i]<<' ';
    // cout<<'\n';
    
    for(int i=1;i<=it;i++)
    {
        while(que.size()&&c[i]>-que.top())que.pop();
        int f= 0 ;
        if(que.size()&&c[i]<=-que.top())
        {

             f=1;
             que.pop();
        }
       
        if(f)continue;
        else return 0;

    }
     
    return 1;
    
}
void solve()
{  
    // int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1,f1);
    int l=0,r=1e9+1;
    while(l+1<r)
    {
        int mid =(l+r)>>1;
        // cout<<check(mid)<<' '<<mid<<'\n';
        // cout<<"------\n";
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l<<'\n';


   
   

}
// 
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t =1;
    cin>>t;
    while(t--)solve();
}