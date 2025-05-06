#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<-1<<'\n';
        return;
    }
    ll sum = (ll)1<<35;
    ll ma =max(a,b);
    cout<<sum-ma<<'\n';


   //cout<<res<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
       { solve();
       }
}