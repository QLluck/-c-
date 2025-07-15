#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =1e5+7;
pair<int,int> arr[N];
pair<int,int> st[N][20];
void init_st(int n)
{
     map<int,int> mp;
     for(int i =1; i<=n;i++)
     {
         mp[arr[i].first]++;
         arr[i].second = mp[arr[i].first];
     }
     for(int i =1; i<=n;i++)st[i][0].second = arr[i].first,st[i][0].first =arr[i].second; 
     int k = log(n)/log(2)+1;
     for(int j = 1; j<k ;j++)
     {
          for(int i =1; i<= n-(1<<j)+1;i++)
          {
              st[i][j-1].first <=st[i+(1<<(j-1))][j-1].first? st[i][j].second 
          }
     }
    }    

void solve()
{

  


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}