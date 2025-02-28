// 顺序表
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,x;
    cin>> n>>x;
     int num = 0 ;
     int num2 = 0;
     int n1 = x;
     int flag = 1;
     while(n1)
     {
          if( (n1&1)&&flag )
              num++;
          else
              flag = 0;
          num2++;
          n1 >>= 1;
          //cout << 1 << '\n';
     }

    int sum = 0;
 if(num==num2&& ( (1<<(num-1)) <n&& n<=x ))
 {
     for (int i = 1; i <=n; i++)
     {
         cout << sum << ' ';
         sum++;
         if (sum >= (1 << num))
             sum = 0;
     }
     cout << '\n';

     return;
 }
 for (int i = 1; i < n; i++)
    {
        cout << sum << ' ';
        sum++;
        if (sum >= (1 << num))
            sum = 0;
     }
     cout << x << '\n';
    
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}