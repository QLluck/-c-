#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int b[N];
int ita;
pair<int,PII> b1[N];
pair<int,PII> a1[N];
int itb;
int n, k;

void solve()
{
    
    cin >> n;
    ita =0;
    itb=0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    int l = -1;
        for (int i = 1; i <= n; i++)
    {
        if (l != a[i])
        {
            l = a[i];
            a1[++ita].fi = l;
            a1[ita].se.fi=i;
            a1[ita-1].se.se=i-1;
        }
    }
    a1[ita].se.se=n;

    l = -1;
    for (int i = 1; i <= n; i++)
    {
        if (l != b[i])
        {
            l = b[i];
            b1[++itb].fi = l;
            b1[itb].se.fi=i;
            b1[itb-1].se.se= i-1;
        }
    }
    b1[itb].se.se=n;
    int na =1,nb=1;
    int f1= 1 ;
    for(int i=1;i<=ita;i++)
    {
        na = i;
        nb=1;
         f1= 1 ;
        if(a1[i].fi==b1[nb].fi)
        {
    while(na<=ita && nb<=itb)
    {
        // cout<<na<<' '<<nb<<'\n';
        if(a1[na].fi==b1[nb].fi)
        {
            // cout<<b1[nb-1].fi <<' '<< b1[nb].fi<<'\n';
            if(f1)na++,nb++,f1=0;
            else if(b1[nb-1].fi >= b1[nb].fi)na++,nb++;
            else 
            {
                if(b1[nb-1].se.fi >a1[na].se.fi  )break;
                else na++, nb++;
            }
            
        }
        else if((a1[na].fi>b1[nb].fi )&&( a1[na].se.fi<b1[nb].se.fi )) break;
        else na++;
    }
}
    if(itb+1==nb)
    { cout<<"YES"<<'\n';
        return;
    }

    }
   cout<<"NO"<<'\n';


}
// 3 2 1 2 0 0 0 0 0 0 0 0
// 3 3 3 2 2 2 1 1 1 2 2 2
// 3 2 3 0 0 2 1 0 0 2 0 0
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}