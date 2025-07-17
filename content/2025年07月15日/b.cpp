#include<bits/stdc++.h>
using namespace std;
const int N =2e5+7;
int h[N]={0},cnt;
struct node
{
     int u,v,next;
};
node t[N*4]={0};
void insert(int u ,int v)
{
     t[++cnt].u=u;
     t[cnt].v=v;
     t[cnt].next=h[u];
     h[u]=cnt;
}
int me[N][4]={0};
int dp[N][4]={0};
int ans= 0 ;
map<int,int>mp;
int dfs(int u)
{   
   int size=0;
   int d= 0 ;
   int e1 = h[u];
   int e2 = t[e1].next;
   int e3 = t[e2].next;
  
   if(e1)size++;
   if(e2)size++;
   if(e3)size++;

   if(e1&&t[e1].v==u)d=size;
   if(e2&&t[e2].v==u)d=size-1;
   if(e3&&t[e3].v==u)d=size-2;

   d = (d%size)+1;

   if(me[u][d])return  ans+dp[u][d];
     me[u][d]=1;

  int e =0 ;
  if(size==1)e=e1;
  else if(size==2)
  {
     if(d==1)e=e2;
     else if(d==2)e=e1;
  }
  else if(size==3)
  {
     if(d==1)e=e3;
     else if(d==2)e=e2;
     else if(d==3)e=e1;
  }
  if(!mp[e])
  {  ans++;
    mp[e]=1;
  }
  cout<<u<<' '<<d<<'\n';
  dfs(t[e].v);
  dp[u][d] = ans;
  return ans;

}
void solve()
{
     int n;
     cin>>n;
     for(int i =1; i<=n;i++)h[i]=0;
     for(int i =1; i<=n;i++)
     {
         int d ;
         cin>>d;
         for(int j =1; j<=d ;j++)
         {
             int v;
            cin>>v;
             insert(i,v);
         }
     }
     for(int i=1 ;i<=n;i++)
     {   if(dp[i][1])
        {
            cout<<dp[i][1]<<'\n';
            continue;
        }
        ans=0;
        mp.clear();
        me[i][1]=1;

           int size=0;
   int d= 0 ;
   int e1 = h[i];
   int e2 = t[e1].next;
   int e3 = t[e2].next;
  
   if(e1)size++;
   if(e2)size++;
   if(e3)size++;

     int e =0 ;
  if(size==1)e=e1;
  else if(size==2)
  {
     e =e2;
  }
  else if(size==3)
  {
   e=e3;
  }
         dfs(t[e].v);
         dp[i][1]=ans;
         cout<<dp[i][1]<<'\n';
     }

}
int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  solve();
}