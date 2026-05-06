#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define se second 
#define fi first 
const int N = 2e5+7;
const double MI = 1e-6;

PII a[N];
int n;
priority_queue<int> que1;
priority_queue<int> que0;
int b[N],itb=0;
multiset<int> set1 ;
// multiset<int> set0;
bool check(int mid)
{
     set1.clear();
    //  set0.clear();
     int it =1;
     int f = a[1].se;
     while(it<=n)
     {
        if(set1.empty())f=a[it].se;
        if(f==a[it].se)
        {
            set1.insert(a[it].fi);
        }
        else 
        {
            auto c =  set1.lower_bound(mid-a[it].fi) ;
            if(c==set1.end())return 0;
            set1.erase(c);
            // if(set1.empty())f=!f;
        }
        it++;
     }
     return 1;
}
void solve()
{
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i].fi;
   for(int i=1;i<=n;i++)cin>>a[i].se;
//    int it =1 ;
//    int  f = a[1].se;
    int l= 0 ;
    int r = 1e9+7;
    while(l+1<r)
    {

        int mid = (l+r)>>1;
        int ch = check(mid);
        // cout<<mid <<' '<< ch<<'\n';
        if(ch)l=mid;
        else r= mid;
    }
    cout<<l<<'\n';
    
//    while(it+1<=n&&a[it+1].se==a[it].se)
//    {
//     // it++;
//     if(f)que1.push(a[it].fi);
//     else que0.push(-a[it].fi);
//     it++;
//    }
//     if(f)que1.push(a[it].fi);
//     else que0.push(-a[it].fi);
//     it++;
//     f=!f;
//     int ans = 1e9+7;
//    while(it<=n)
//    {

//     while(it+1<=n&&a[it+1].se==a[it].se)
//    {
//     // it++;
//     if(f)que1.push(a[it].fi);
//     else que0.push(-a[it].fi);
//     it++;
//    }
//     if(f)que1.push(a[it].fi);
//     else que0.push(-a[it].fi);
//     it++;
//     f=!f;
//     if(it<=n)
//     {
//        while(que1.size()&&que0.size())
//        {

//        }
        
//     }
//     else if(it>n)
//     {

//     }

//    }

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;

    t=1;
    while(t--)
    solve();
}
// 1 2 3 4 
// 1 1 1 1
// 1 1     0
// 1 1 1    1
// 1 2