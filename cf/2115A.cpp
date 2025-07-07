#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int arr[N] = {0};
int gcd(int a ,int b )
{  if(a>b)
        swap(a, b);
     while(a)
     {
         int temp = b % a;
         b = a;
         a = temp;
     }
     return b;
}
void printb(int b)
{
     if(b>1)
         printb(b / 2);
     cout << b % 2;
}
void solve()
{
    int n;
    n = 50; 
    for (int i = 1; i <= n;i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            printb(i);
            cout << '\n';
            printb(j);
            cout << '\n';
            printb(gcd(i, j));
            cout << '\n';
            cout << '\n';
                            }
    }
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
   // cin >> t;
    //while (t--)
        solve();
    //printb(2);
}