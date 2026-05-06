#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e6+7;

int ans[N];
int me[N];
// struct node
// {
//     int fi,se,id;
//     bool operator> ( node b)
//     {
//        if(this->se==b.se)return this->fi<b.fi;
//        else return this->se<b.se;
//     }
// };
priority_queue<pair<int, PII > > que;
pair<int,PII> a[N];
// priority_queue<pair<int, PII > > que2;
void solve()
{
 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se.fi;
        a[i].se.se=i;
    }
    sort(a+1,a+n+1);
    int ita =1;
    int it =0 ;
    for(int i=1;i<=n;i++)
    {
        int num = i-1;
        while(ita<=n && a[ita].fi == num)
        {
            pair<int,PII> c;
            c.fi = -a[ita].se.fi;
            c.se.fi= a[ita].fi;
            c.se.se = a[ita].se.se;
            ita++;
            que.push(c);
        }
        while(que.size() && num>(-que.top().fi))que.pop();
        if(que.size() &&  (que.top().se.fi) <= num && num<=(-que.top().fi) )
        {
            ans[++it]=que.top().se.se;
            que.pop();

        }
        else break;

    }
 
    cout<<it<<'\n';
    for(int i=1;i<=it;i++)cout<<ans[i]<<' ';
    cout<<'\n';
   

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}