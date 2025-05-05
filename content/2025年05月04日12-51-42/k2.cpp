#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
const int N =1e3+7;
int a[N][N]={0};
int b[N][N]={0};
int X,Y;
int ans =0;

int rx[2]={0,1};
int ry[2]={1,0};

void dfs(int x ,int y,ll sum)
{   if(ans)return;
      for(int i =0;i<2 ;i++)
      {   if(ans)return;
            int x1 = x+rx[i];
            int y1  =  y+ry[i];
            if(x1>X||y1>Y)continue;
            
             ll p =  a[x1][y1]-a[1][1]-sum-b[x1][y1] ;
            // cout<<x1<<' '<<y1<<' '<<p<<' '<<a[x1][y1]<<' '<<sum<<' '<<b[x1][y1]<<'\n';
             if(p<0)continue;

             if(x1==X||y1==Y)
              { ans=1;
              // cout<<"YES"<<'\n';
                return;
              }
             
             dfs(x1,y1,sum+b[x1][y1]);

         
      }
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
   dfs(1,1,b[1][1]);
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