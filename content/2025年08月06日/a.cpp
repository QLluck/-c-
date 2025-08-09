#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int a[N]={0};
void solve()
{
     int n;
     cin>>n;
     map<int,int>mp;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         mp[a[i]]++;
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=i;j<=n;j++)
         {
             int ans = a[i]| a[j];
             if(mp[ans])continue;
             else 
             {
                cout<<"NO"<<'\n';
                return;
             }
         }
     }
     cout<<"YES"<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}