#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
ll si(string s)
{
    ll res = 0;
    ll sum = 1;
    for (int i = s.size() - 1; i >= 0;i--)
    {
         res+= (s[i]-'0') *sum;
         sum *= 4; 
    }
    return res;
}
string shi(ll x )
{
    string s = "";
    while(x)
    {
        s = s + char(x % 4 + '0');
        x /= 4;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll ju(ll x ,ll y )
{
    x--;
    y--;
    string s = "";
    ll sum1 = 1;
    while(sum1<=y)
        sum1  *= 2;
    ll sum2 = 1 ;
    while(sum2<=x)
        sum2 *= 2;
    ll sum = max(sum1, sum2);
    //cout << sum << '\n';
    while(sum>1)
    {
        int sum3 = sum / 2;

        if (sum3 > y && sum3 > x)
        {

            s = s + "0";
        }
             else if (sum3 > y&&sum3<=x)
             {
                 x -= sum3;
                 s = s + "2";
             }
             else if (sum3 <= y&&sum3>x)
             {
                 y -= sum3;
                 s = s + "3";
             }
             
             else if (sum3 <= y && sum3 <= x)
             {
                 x -= sum3;
                 y -= sum3;
                 s =s+ '1';
             }

             sum = sum3;
            // cout << sum3 << ' ' << x << ' ' << y << endl;
    }
  //  cout << s << endl;
    // cout << si(s) << '\n';
    return si(s)+1 ;
}
void cha(string s)
{
    ll x1 = 1;
    ll y1 = 1;
    ll sum = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        
           
         if (s[i] == '1')
        {
            x1 += sum;
            y1 += sum;
        }
        else if (s[i] == '2')
        {
            x1 += sum;
        }
        else if (s[i] == '3')
        {
            y1 += sum;
        }
        sum *= 2;
       
    }
     // cout << s << '\n';
    cout << x1 << ' ' << y1 << '\n';
}
void solve()
{
    ll res = 0;
    int n;
    cin >> n;
    int q;
    cin >> q;
    string s1;
    while(q--)
    {
        string s;
        cin >> s;
        if(s=="->")
        {
            ll x, y;
            cin >> x >> y;
            cout << ju(x, y) << '\n';

        }
        else 
        {
            ll x;
            cin >> x;
            x--;
            string s2 = shi(x);
            cha(s2);
        }
       
    }
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
       { solve();
        //    int x, y;
        //    cin >> x >> y;
        //    cout << ju(x, y) <<endl;
        // int x;
        // cin >> x;
        // string s = shi(x);
        // cha(s);
       }
    // string s = shi(32770);
    // string s1 = shi(53376);
    // cout << s << '\n';
    // cout << s1 << '\n';
    // cha(s);
    // cha(s1);
    // cout << ju(130, 1) << '\n';
    // cout << ju(73, 193) << '\n';
    // for (int i = 1; i <= 100;i++)
    //     cout << shi(i) << '\n';
}