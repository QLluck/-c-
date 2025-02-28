// 顺序表
#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
void solve()
{
    int n ;
    cin>>n ;
    int num1 = n/15 ;
    int num2 = n%15 ;
    int sum = num1*3 ;
     sum+= num2<=2?num2+1:3 ;
     cout<<sum<<'\n';

       
   
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}