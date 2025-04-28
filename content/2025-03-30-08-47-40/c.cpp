#include<bits/stdc++.h>
using namespace std ;
const int N =3e5+7;
#define ll long long 
struct node
{
     int v,next;
};
node t[N]={0};
int it =0;
int h[N]={0};
int arr[N]={0};

void ad(int u,int v)
{
      t[++it].v = v ;
      t[it].next=h[u];
      h[u]=it;


}
int n;

int bfs(int x )
{
    queue<int> que;
      que.push(x);
      map<int,int>mp;
      mp[x]=1;
      int num=0;
      while(!que.empty())
      {
        
        int u = que.front();
        que.pop();
        num++;
       // cout<<u<<'\n';
        for(int i =h[u];i!=0;i=t[i].next)
        {     // cout<<arr[u]<<' '<<arr[t[i].v]<<'\n';
              if(arr[u]<=2*arr[t[i].v])
              {     if(mp.count(t[i].v))continue;
                    mp[t[i].v]=1;
                    que.push(t[i].v);
              }
            
        }


      }
      return num==n;
    
}
void solve()
{
    cin>>n;
    it=0;
    
    for(int i=1;i<=n;i++)h[i]=0;
   // cout<<2<<'\n';
    for(int i=1; i<=n ;i++)
    {
         cin>>arr[i];
    }
   // cout<<1<<'\n';
    for(int i=1;i<=n-1 ;i++)
    {
         int u,v;
         cin>>u>>v;
         ad(u,v);
         ad(v,u);
    }
  //  cout<<"yes"<<'\n';
    int ans =0 ;
    for(int i=1 ;i<=n;i++)
    {    
         if(bfs(i))ans++;
         //cout<<"----------"<<'\n';
    }

    // for(int i=1 ;i<=n ;i++)
    // {
    //       for(int j =h[i] ;j!=0 ;j=t[j].next)
    //       {
    //           cout<<i<<' '<<t[j].v<<'\n';
    //       }
    // }
    cout<<ans<<'\n';

  


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
   cin>>t;
   while(t--)
    solve();
  
}