#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;

pair<int,int> a[N] ;
int dp1[N];
int dp2[N];
int b[N]={0};
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
     for(int i=1;i<=n;i++)
     {  int num =0;
         for(int j =1;j<=sqrt(i) ;j++)
         {
            if(i%j==0)
            {
               num+=2;
            }
         }
         if( (int)sqrt(i) == sqrt(i) )num--;

        if(num!=2&&(!me[num])) cout<<i<<' '<<num<<' '<<sqrt(i)<<'\n';
     }

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    pri();
    solve();
}