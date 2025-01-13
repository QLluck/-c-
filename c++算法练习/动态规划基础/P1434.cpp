#include<bits/stdc++.h>
using namespace std ;
const int N =107 ;
int arr[N][N]={0} ;
int X,Y ;
int dp[N][N] = {0} ;
struct node
{
     int x;
     int y ;
};
queue<node> que; 
int rx[4] ={0,0,1,-1} ;
int ry[4] ={1,-1,0,0} ;
int ans= 0 ;
void bfs(int x,int y)
{
      if(dp[x][y]) return ;
      node s  = {x,y} ;
      dp[s.x][s.y]=1 ;
      que.push(s) ;
      while(!que.empty())
      {
          node u = que.front() ;
          que.pop() ;
          for(int i = 0 ;i <4 ;i++)
          {
             int x1 = rx[i] + u.x ;
             int y1 =ry[i] +u.y ;
             int p = dp[u.x][u.y]+1 ;
             if(x1<0||x1>=X||y1<0||y1>=Y|| arr[x1][y1] >= arr[u.x][u.y] ||p <=dp[x1][y1]  )continue ;
             dp[x1][y1] = p ;
             ans = max(p,ans) ;
             node temp = {x1,y1} ;
             que.push(temp) ;
          }
      }

}
void solve()
{
    cin>>X>>Y ;
    
    for(int i = 0 ; i <X ;i++)
    {
        for(int j =0 ; j<Y ;j++)
        {
             cin>>arr[i][j] ;
        }
    }
    for(int i = 0 ; i<X ;i++)
    for(int j= 0 ; j<Y ;j++)
      bfs(i,j) ;
      cout<<ans<<'\n' ;

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve() ;
 }