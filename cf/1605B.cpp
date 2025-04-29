#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n ;
const int N =2e5+7;
int arr[N]={0},it;

void solve()
{
   int n;
   cin>>n;
   string s ;
   cin>>s;
   int l = 0; 
   it =0;
   int r = n-1 ;
   while(l<r)
   {
        while(l<r&&s[r]=='1')r--;
        while(l<r&&s[l]=='0')l++;
        if(l<r)
        {
        arr[++it]=l+1;
        arr[++it]=r+1;
        }
        r--;
        l++;
   }
   sort (arr+1,arr+it+1);
   if(it==0)
   {
    cout<<0<<'\n';
    return;
   }
   cout<<1<<'\n';
   cout<<it<<' ';
   for(int i = 1; i<=it ;i++)cout<<arr[i]<<' ';
   cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}