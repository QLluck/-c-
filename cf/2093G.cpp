#include<bits/stdc++.h>
using namespace std ;
int n,k;
const int N = 2e5 + 7;
int arr[N] = {0};
int pix[N] = {0};
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
        pix[i] = arr[i] ^ pix[i - 1];
    }
     
} 
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        
    solve();
}