#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 507;

int ma[70] = {0};
int mb[70] = {0};
int mc[70] = {0};
int md[70] = {0};
void z(ll x,int me[] )
{
   
    for (int i = 61;i>=1; i--)
    {
         if(x&1)
             me[i] = 1;
         x >>= 1;
    }
}
void solve()
{
    ll b, c, d;
    cin >> b >> c >> d;
    for (int i = 1; i <= 64;i++)
    {
        ma[i] = 0;
        mb[i] = 0;
        mc[i] = 0;
        md[i] = 0;
    
    }
    z(b, mb);
    z(c, mc);
    z(d, md);
    ll flag = 0;
    for (int i = 1; i <= 61;i++)
    {
        flag *= 2;
        flag += md[i];

        if (mb[i]==0&&mc[i]==0)
        {
            if(flag==0)
                ma[i] = 0;
            else if(flag==1)
             {   ma[i] = 1;
                 flag--;
             }
            else if(flag>=2)
            {
                ma[i] = 1;
                flag--;
            }
        }
        else if (mb[i]==1&&mc[i]==1)
        {
            if(flag==0)
               {
                   cout << -1 << '\n';
                   return;
               }
            else if(flag==1)
             {   ma[i] = 0;
                 flag--;
             }
            else if(flag>=2)
            {
                ma[i] = 1;
                flag-=2;
            }
        }
        else if (mb[i]==1&&mc[i]==0)
        {
            if(flag==0)
               {
                   cout << -1 << '\n';
                   return;
               }
            else if(flag==1)
             {   ma[i] = 0;
                 
             }
            else if(flag>=2)
            {
                ma[i] = 1;
                flag-=2;
            }
        }
        
        else if (mb[i]==0&&mc[i]==1)
        {
            if(flag==0)
                ma[i] = 0;
            else if(flag==1)
               { ma[i] = 1;

               }
            else if(flag>=2)
            {
                ma[i] = 1;
                flag-=2;
            }
        }
        if (flag >= 2)
        {
            cout << -1 << '\n';
            return;
        }
    }
    if(flag>0)
    {
        cout << -1 << '\n';
        return;
    }
    ll sum= 0 ;
    ll ji =1;
    for (int i = 61; i >= 1;i--)
    {
        sum = sum + ji * ma[i];
        ji <<= 1;
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}