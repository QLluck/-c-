#include <bits/stdc++.h>
using namespace std;
const int N =2e5+7;
int arr[N] = {0};
int me[N]={0};
queue<int> que;
int bfs(priority_queue<pair<int,int> >& qu)
{
    while(qu.size())
    {   if(me[qu.top().first])
        {
            qu.pop();
            continue;
        }
         que.push(qu.top().first );
           while(que.size())
           {
                int u = que.front();
                que.pop();
                for(int i = 0 ;i<2 ;i++)
                {
                         int x = i ? u+1:u -1;
                         
                }
           }
         qu.pop();
    }

}
void solve()
{
   int n;
   cin>>n;
   for(int i =1; i<=n;i++)
   {
     cin>>arr[i];
     me[i]=0;
   }
   priority_queue<pair<int,int > > que;
   for(int i =1; i<=n;i++)
   {
     
     que.push(make_pair(arr[i],i) );
   }
int ans = bfs(que);
 
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}