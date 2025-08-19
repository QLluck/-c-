#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N]={0};


int me[N]={0};
void solve()
{
   
    int n;
    cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   int ans =0 ;
   ans ++;
   map<int,int> mp;
   map<int,int> cu ;
   mp[a[1]]++;
   int d =1;
   int f = 1;
   queue<int> que;
   for(int i=2 ;i<=n;i++)
   {
       if(mp[a[i]]&&cu[a[i]]==0)
       {
        d--;
        cu[a[i]]++;
        //mp[a[i]]++;

       }
       else if(mp[a[i]]==0&&cu[a[i]]==0)
       {
           cu[a[i]]++;
           f++;
       }

       if(d==0)
       {
         ans++;
         for (auto &j:cu)
         {
            mp[j.first] ++;
         }
         d=f;
         cu.clear();

       }
       
   }
   cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}