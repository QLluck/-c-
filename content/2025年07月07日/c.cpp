#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 507;
const ll  P = 998244353;
int arr[N][N]={0};
int me[N][N]={0};
int X,Y,k;
struct node
{
    int x,y,s;
};
queue<node> que;
int rx[4] ={0,0,1,-1};
int ry[4] ={1,-1,0,0};
int flag =1;
void bfs(int sx,int sy)
{
     node su = {sx,sy,0};
     que.push(su);
     while(que.size())
     {
         node u = que.front();
         que.pop();
         for(int i =0 ;i<4 ;i++)
         {
             int x1 = rx[i]+u.x ;
             int y1 = ry[i]+ u.y;
             int s = u.s +1;
             if(x1<=0||x1>X || y1<=0 || y1>Y || arr[x1][y1]|| (me[x1][y1]!=0&&me[x1][y1]<=s))continue;
             me[x1][y1]=s;
             node temp = {x1,y1,s};
             que.push(temp);
             flag=0;
             
         }

     }
}
void solve()
{  
   
 cin>>X>>Y>>k;
 for(int i =1; i<=k ;i++)
 {
      int x,y,d;
      cin>>x>>y>>d;
      int x1 = max(1,x-d);
      int y1 = max(1,y-d);
      int x2 = min(X,x+d);
      int y2 = min(Y,y+d);
      arr[x1][y1]+=1;
      arr[x1][y2+1]-=1;
      arr[x2+1][y1]-=1;
      arr[x2+1][y2+1]+=1;


 }
//  for(int i =1; i<=X ;i++)
//  {
//      for(int j =1; j<=Y ;j++)
//      {
//         cout<<arr[i][j]<<' ';
//      }
//      cout<<'\n';
//  }
 for(int i =1;i<=X ;i++)
 for(int j =1; j<=Y ;j++)
   arr[i][j]=arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
//    for(int i =1; i<=X ;i++)
//    {
//        for(int j =1; j<=Y ;j++)
//        {
//           cout<<arr[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
for(int i =1; i<=X;i++)
{
     for(int j =1; j<=Y;j++)
     {
         if(arr[i][j])bfs(i,j);
     }
}

int ans =0 ;


for(int i =1; i<=X ;i++)
{
     for(int j =1; j<=Y ;j++)
     { ans=max(me[i][j],ans);
       // cout<<me[i][j]<<' ';
     }
     //cout<<'\n';
}
   cout<<ans-1<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}