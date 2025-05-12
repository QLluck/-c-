#include<bits/stdc++.h>
const int N =500+7;
using namespace std ;
#define ll long long 
char arr[N][N];
int X,Y,K;
struct node
{
     int x,y,num;
     int f;
};
int rx[2]={0,1};
int ry[2]={1,0};
int ans =0;
queue<node> que;

void bfs()
{
    node s;
    s.x=1;
    s.y=1;
    s.num=K;
    s.f=0;
    if(arr[1][1]=='1')s.f++;
    que.push(s);
    if(arr[1][1]=='?')
    {
         if(K>0)
         {
            node s2;
            s2.x=1;
            s2.y=1;
            s2.num=K-1;
            s2.f=1;
            que.push(s2);
         }
    }
    while(que.size())
    {
         node u = que.front();
         que.pop();
         if(u.x==X&&u.y==Y)ans=max(ans,u.f);
         for(int i=0 ;i<2; i++)
         {
             int x1 = u.x +rx[i];
             int y1 =u.y+ry[i];
             if(x1<=0||x1>X||y1<=0||y1>Y)continue;
             int f =u.f ;
             if(arr[x1][y1]=='1')f++;
             node temp;
             temp.x =x1;
             temp.y=y1;
             temp.f=f;
             temp.num=u.num;
             que.push(temp);
             if(arr[x1][y1]=='?'&&u.num>=1)
             {
                 temp.num=u.num-1;
                 temp.f=u.f+1;
                 que.push(temp);
             }

         }
    }

    
}
void solve()
{
 ans =0 ;

  cin>>X>>Y>>K;
  for(int i =1; i<=X;i++)
  {
    for(int j =1; j<=Y ;j++)
    {
        cin>>arr[i][j];
    }
  }
  if(X==1&&Y==1)
  {
     if(arr[1][1]=='1')cout<<1<<'\n';
     else if(arr[1][1]=='?'&&K>=1)cout<<1<<'\n';
     else cout<<0<<'\n';
     return;
  }
  bfs();
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