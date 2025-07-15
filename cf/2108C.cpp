#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int arr[N] = {0};

int me[N]={0};
queue<int> que;
int n;
int ans= 0;
void bfs( priority_queue<pair<int,int> >&qu)
{
     while(qu.size())
     {
         if(me[qu.top().second]==0)que.push(qu.top().second);
         qu.pop();
         if(que.size())
          { ans++;
            me[que.front()]=1;
            
          }
         while(que.size())
         {
            int u = que.front();
            que.pop();
            for(int i =0 ;i<2 ;i++)
            {
                 int x1 = i?u+1:u-1;
                 if(x1<=0||x1>n||me[x1]||arr[u]<arr[x1])continue;
                 me[x1]=1;
                 que.push(x1);
            }
         }

     }
}
void solve()
{
 
   cin>>n;
   ans=0;
   for(int i =1; i<=n;i++)
   {
    cin>>arr[i];
    me[i]=0;
   }
   priority_queue<pair<int,int> > qu;
   for(int i =1; i<=n;i++) qu.push(make_pair(arr[i],i));
   bfs(qu);
   cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}