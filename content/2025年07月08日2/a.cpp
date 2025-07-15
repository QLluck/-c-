#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =2e5+7;
pair<int,int > arr[N];
int it =0;
void solve()
{
   int n;
   cin>>n;
   map<int,int> mp;
   it =0 ;
   for(int i =1; i<=n;i++)
   { 
     int a; 
     cin>>a;
     if(mp[a]==0)arr[++it].first=a;
     mp[a]++;
    
   }
   for(int i =1; i<=it;i++)
   {
     arr[i].second = mp[arr[i].first] ;
   }
   sort(arr+1,arr+it+1);
   int sum =arr[it].second;
   for(int i = it-1;i>=1 ;i--)
   {
     if(arr[i].second>sum)
     {
        cout<<"NO"<<'\n';
        return;
     }
     else 
     {
         sum+=arr[i].second;
     }
   }
   

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}