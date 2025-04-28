#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7 ;
const int inf =1e9+7;
int arr[N]={0};
void solve()
{int n;
    cin>>n;
    for(int i =1;i<=n;i++)cin>>arr[i];
    int l = -inf; 
    int r =inf;
    for(int i =1; i<=n;i++)
    {
        int l1 =max(1,i-arr[i]+1);
        int r1=min(n, arr[i]+i-1);
        l=max(l1,l);
        r=min(r1,r); 
    }
    cout<<l<<' '<<r<<'\n';
    if(r<l)cout<<0<<'\n';
    else cout<<r-l+1<<'\n';





    



}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    
    int t; 
   // cout<<"YES"<<'\n';
    cin>>t;
    while(t--)
    solve();
}