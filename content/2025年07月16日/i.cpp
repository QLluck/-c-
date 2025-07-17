#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e3+7;
const int P =998244353;
 int arr[N][N]={0};
int rx[4]={0,1,0,-1};
int ry[4]={1,0,-1,0};
void solve()
{  
   int n;
   cin>>n;
   string s;
   cin>>s;
   int l ,r;
   cin>>l>>r;
   if(s[0]==s[n-1])
   {
    cout<<"Yes"<<'\n';
    return;
   }
   if(l==1||r==n)
   {
     cout<<"Yes"<<'\n';
     return;
   }
   else cout<<"No"<<'\n';
    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}