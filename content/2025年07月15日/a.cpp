#include<bits/stdc++.h>
using namespace std;
const int N =5e5+7 ;
int arr[N]={0},it;
void solve()
{
     int n;
     cin>>n;
     map<int,int> mp;
     for(int i =1; i<= n;i++)
     {
         for(int j =i;j <=n ;j++)
         {
             if(mp[j*j-i*i])continue;
             arr[++it] = j*j-i*i;
             mp[arr[it]]=1;
         }
     }
     sort(arr+1,arr+it+1);
     for(int i =1; i<=it;i++)cout<<arr[i]<<' ';
     cout<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}