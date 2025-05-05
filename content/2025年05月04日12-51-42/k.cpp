#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
const int N =1e3+7;
ll a[N][N]={0};
ll b[N][N]={0};
int X,Y;
struct node
{
     int x,y;
     ll sum;
};
int rx[2]={0,1};
int ry[2]={1,0};
queue<node> que;
int bfs()
{
  node s = {1,1,b[1][1]};
  que.push(s);
  while(!que.empty())
  {
      node u = que.front();
      que.pop();
   for(int i =0; i<2;i++)
   {
     int x1= u.x+rx[i];
     int y1= u.y+ry[i];
    
     if(x1>X||y1>Y)continue;
     ll sum = u.sum + b[x1][y1];
     ll p = a[x1][y1] -a[1][1] -sum;
     //cout<<x1<<' '<<y1<<' '<<p<<'\n';
     if(p<0)continue;
     if(x1==X||y1==Y)return 1;
     node temp;
     temp.x=x1;
     temp.y=y1;
     temp.sum=sum;
     que.push(temp);
     
   }
  }
return 0;
}
void solve()
{
  cin>>X>>Y;
  for(int i =1; i<=X; i++)
  {
     for(int j =1; j<=Y ;j++)
     {
         cin>>a[i][j];
     }
  }
  for(int i =1; i<=X; i++)
  {
     for(int j =1; j<=Y ;j++)
     {
         cin>>b[i][j];
     }
  }
  int ans =bfs();
  if(ans)
  {
    cout<<"YES"<<'\n';
  }
  else cout<<"NO"<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}