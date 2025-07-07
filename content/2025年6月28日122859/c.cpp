#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
int arr[N] = {0};
ll s(ll a ,ll l,ll r)
{
    ll sum = 0; 
    while(a)
    {
        if(a&1)
        {   if((l&1!=0) &&(r&1!=0) )
            sum = sum + sum + 1;
        }
        a /= 2;
        l /= 2;
        r /= 2;
    }
    return sum;
}
ll s2(ll a, ll l)
{
    ll sum = 0 ;
    while (a)
    {
        if (a & 1)
        {
            if ((l & 1 != 0) )
                sum = sum + sum + 1;
        }
        a /= 2;
        l /= 2;
       
    }
    return sum ;
}
void solve()
{
    ll n, m; 

    cin >> n>>m;
    
    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = 0;
    ll ans = 0;
    for (int i = 2; i <= n-1;i++)
    {
        ll l = arr[i] | arr[i - 1];
        ll r = arr[i] | arr[i + 1];
        ans += s(l & r,arr[i-1],arr[i+1]);
        //cout << s(l & r,arr[i-1],arr[i+1]) << '\n';
        }
        ans += s2(arr[1] | arr[2], arr[2]);
        ans += s2(arr[n] | arr[n-1], arr[n-1]);
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}