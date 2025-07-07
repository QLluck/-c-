#include<bits/stdc++.h>
using namespace std;
const int N = 12;
int s1[N] = {0};
int s2[N] = {0};
string  f(int x )
{
    string s = "";
    while(x)
    {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    return s;
}
int f2(string  s )
{
    int sum = 1;
    int res = 0; 
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int ge = s[i] - '0';
        res += sum * ge;
        sum *= 10;
    }
    return res;
}
int num(int x ,int y )
{
    int res = 0; 
    while(x||y)
    {
         if(x%10==y%10)
             res++;
         x /= 10;
         y /= 10;
    }
    return res  ; 
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int ma = max(l, r);
    int mi = min(l, r);
    r = ma - mi;
    string s1 = f(ma);
    string s2 =f(mi);
    int n = s1.size() - 1;
    int jin = 0;
    int ans = 0; 
    for (int i = n; i >= 0; i--)
    {
        int gma = s1[i] - '0';
        int gmi = s2[i] - '0';
        
        gma += jin * 10;
        jin = 0;
        if((gma-gmi) ==1)
        {
            ans++;
            jin += 1;
        }
        else if((gma-gmi)==0)
        {
            ans += 2;

        }
        else
            break;
    }
    cout << ans << '\n';
    // int flag = 0;
    // for (int i = s.size() - 1; i >= 0; i--)
    // {
    //     int ge = s[i] - '0';
    //     if(flag==0)
    //     {   
    //          if(ge>=2)
    //          {
    //              s2 += '1';
    //              flag = 1;
    //             }
    //          else if(ge==1) 
    //          {
    //              s2 += '0';
    //              flag = 1;
    //          }
    //          else if(ge==0)
    //          {
    //              s2 += '0';
                
    //          }
    //     }
    //     else
    //         s2 += ge==9?'1':(char)(ge+1+'0');
    // }
    // int x = f2(s2) + mi;
    // cout << r << '\n';
    // cout << f2(s2) << '\n';
    // cout << x << '\n';
    // cout << num(x, ma) + num(x, mi) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}