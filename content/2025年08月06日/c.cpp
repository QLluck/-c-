#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+7;

int a[N];
int dp1[N];
int dp2[N];
// int b[N]={0};
int prime[N],it;
int me[N];
void pri()
{
    me[1]=1;
    me[0]=1;
    for(int i=2;i<N ;i++)
    {
         if(!me[i])prime[it++]=i;
         for(int j= 0 ;j<it ;j++)
         {
             if(i*prime[j]>=N)break;
             me[i*prime[j]]=1;
             if(i%prime[j]==0)break;
         }
    }
}
void solve()
{
     int n;
     cin>>n;
     it =0 ;
     map<int,int> mp;
     int ans =0 ;
     for(int i=1;i<=n;i++)
     {
        int b;
        cin>>b;
        double er = sqrt(b);
        if(b!=1&&((int)er == er))
        {      int zhi = er;
            if(me[zhi]==0)
            {
                  ans += b;
            }
            else  if(mp[b]==0)
                   {
                        mp[b]++;
                        a[++it]=b;
                   }
                   else mp[b]++;
        }

     }
    // int ans =0; 
     for(int i=1;i<=it;i++)
     {
        int num =0;
          for(int j=1;j<=sqrt(a[i]) ;j++)
          {
             if(a[i]%j)num+=2;
          }
          num--;
          if(me[num]==0)
          {
             ans += mp[a[i]]*a[i];
          }
     }
     cout<<ans<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    pri();
    solve();
}