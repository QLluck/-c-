#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int prime[N]={0}, it;
int arr[N] = {0};
int me[N] = {0};
int pri()
{
    me[0] = 1;
    me[1] = 1;
    for (int i = 2; i < N;i++)
    {
         if(!me[i])
            { prime[it++] = i;
                me[i] = i;
            }
         for (int j = 0; j < it;j++)
         {
             if(i*prime[j]>=N)
                 break;
             me[i * prime[j]] = i ;
             if(i%prime[j]==0)
                 break;
         }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
     {
           arr[i] = i;
           if (me[arr[i]] != arr[i])
               swap(arr[i], arr[me[arr[i]]]);
            
        }
        int ans = 0;
        for (int i = 1; i <= n;i++)if(i==arr[i]) 
                ans++;
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    pri();
    cin >>t;
    while (t--)
        solve();
    //for (int i = 1; i<=t; i++)
      // cout << me[i] << ' ';
}