#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first
#define se second
const int P = 1e9+7;
const int N = 1e6+7;
const int INF = 1e18+7;
int prime[N],it;
int me[N]={0};
int b[N]={0},itb;
int ans = 0;

int gcd(int a,int b)
{
     if(a>b)swap(a,b);
     while(a)
     {
        int tmp = b%a;
        b= a;
        a = tmp;
     }
     return b;
}
void pri()
{
     for(int i=2;i<N;i++)
     {
         if(!me[i])prime[it++]=i;
         for(int j=0;j<it ;j++)
         {
              if(i*prime[j]>=N)break;
              me[i*prime[j]]=1;
              if(i%prime[j]==0)break;
         }
     }
}
void dfs(int d,int sum1,int sum2)
{
      if(d>itb)
      {
          ans = min(ans, sum1 +sum2);
          return;
      }
      dfs(d+1,sum1*b[d],sum2);
      dfs(d+1,sum1,sum2*b[d]);
}
void solve()
{ 
 
  
    int x,y;
    cin>>x>>y;
    int g = gcd(x,y);
    x/=g;
    y/=g;

    int n1= x;
    int n2 = y;
    int i1=0;
    priority_queue<int> que;
    while(i1<it&&prime[i1]<=n1)
    {
        int num =0 ;
         while(n1%prime[i1]==0)
         {
            n1/=prime[i1];
            num++;
           // cout<<prime[i1]<<'\n';
             
         }

         if(num&1)que.push(-prime[i1]);
         i1++;
        
    }
    
   que.push(-n1);
   
    i1= 0;

        while(i1<it&&prime[i1]<=n2)
    {
        int num =0 ;
         while(n2%prime[i1]==0)
         {
            n2/=prime[i1];
            num++;
            // cout<<prime[i1]<<'\n';
             
         }
         if(num&1)que.push(-prime[i1]);
         i1++;
    }

    que.push(-n2);
     while(que.size()>2)
     {
          int a1 = que.top();
          que.pop();
          int a2 = que.top();
          que.pop();
          int a3 = -a1*a2;
          //cout<<a3<<'\n';
          que.push(a3);
     }
     itb=0;
     while(que.size())
     {
          b[++itb]= -que.top();
          que.pop();
     }
     //sort(b+1,b+itb+1);

     //itb = unique(b+1,b+itb+1)-b-1;

     ans = INF;

    dfs(1,1,1);
    // for(int i=1;i<=itb;i++)cout<<b[i]<<' ';
     cout<<ans<<'\n';

    



}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    pri();
    cin>>t;
    while(t--)
    solve();
}