#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
ll arr[N] = {0};
pair<ll, ll> b[N];
ll n, m;
int check(ll mid)
{
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        
    }
    return mid >= sum;
}
void solve()
{
   

    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
    }
    ll mani = 0;
    ll masun = 0;
    ll ton = 0;
    ll maniz = 0;
    ll masunz = 0;
    for (int i = 1; i <= n;i++)
    {
        ll b1;
        cin >> b1;
        ll sun = (b1 - arr[i] + m) % m;
        ll ni = (arr[i] - b1 + m) % m;
        b[i].first = sun;
        b[i].second =ni ;
        // maniz = max(maniz, ni);
        // masunz = max(masunz, sun);
        // cout << sun << ' ' << ni  ;
        // if (sun == ni && sun != 0)
        //     ton = ni;
        // else if(sun<ni)
        //  {   masun = max(masun, sun);
        //     // cout << "sun:" << sun << '\n';
        //  }
        // else if(ni<sun)
        //   { 
        //      mani = max(ni, mani);
        //    // cout<<"ni:"<<ni<<'\n';
        //     }
    }
    ll l = 0;
    ll r = m;
    while(l+1!=r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    //     if(ton)
    //     {
    //          if(mani>masun)
    //              ans = ton + masun;
    //         else
    //             ans = ton + mani;
    //     }
    //     else
    //     {
    //         ans = mani + masun;
    //     }
    //     ll sum1 = min(ans, maniz);
    //    sum1 = min(sum1, masunz);
    //     cout << sum1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}