#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
vector<int> a[507];
int me[100], it;
int me1[100];
int w(int i);
int po(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
            res = res * a;
        b >>= 1;
        a *= a;
    }
    return res;
}
int check(int mid,int yi,int s,int z)
{
    return s >= yi + (z - mid) + mid * 3;
}
void solve()
{
    it = 0;
    int n, k;
    cin >> n >> k;
    int yi = 0;
    int ans = 0;
    while(n)
    {
        me[it] = 0;
        me[it] = n % 3;
        me1[it] = me[it];
        yi += me[it];
        
        n /= 3;
       // ans += me[it]*( po(3, it + 1) + (it ? it * po(3, it - 1) : 0));
       // cout << it << ' ' << ans << '\n';
        it++;
       
    }


    if (k < yi)
        cout << -1 << '\n';
    else
    {
        int s = k;
        for (int i = it - 1; i >= 0;i--)
        {
            if(!me[i]||i==0)
                continue;
            int l = -1;
            int r = me[i] + 1;
            yi -= me1[i];
           // cout << i << '\n';
            while(l+1<r)
            {
                int mid = (l + r) >> 1;
                if(check(mid,yi,s, me[i]))
                    l = mid;
                    else
                    r = mid;
                    //cout << mid << ' ' << yi << ' ' << s << ' ' << me[i] << ' ' << l << ' ' << r << '\n';
            }
           // cout << s << ' ' << l << '\n';
            if(l==-1)
                continue;
            
                me[i - 1] += l * 3;
                s -= me[i]-l ;
               // cout << s << ' ' << l << '\n';
                me[i] -= l;
                //   0 1 2
                //    2 1 0
                //          
                //
        }
        for (int i = 0; i < it;i++)
            ans += me[i]*w(i);
        // for (int i = 0; i < it;i++)
        //     cout << me[i] << ' ';
        // cout << '\n';
        cout << ans << '\n';
    }
}
// 0 0 1 9 
// 9 
// 3 2 0 
// 5 
// 2 1 0 
// 0 3 0
// 2 
// 4

// 3 + x/3 per 1 ;3^x;
int w(int i) { return po(3, i + 1) + (i ? i * po(3, i - 1) : 0); }
signed main()
{
     ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    //cout << 1 << ' ' << 3 << '\n';
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << po(3, i) << ' ' <<w(i)<<' '<<w(i+1)-3*w(i) << '\n';
    // }
}
