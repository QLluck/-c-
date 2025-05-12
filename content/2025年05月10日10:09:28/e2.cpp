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

void dfs(int x,int y ,int num,int f)
{  if(x==X&&y==Y)
    {
         ans =max(ans,f);
        return;
    }
    for(int i =0 ;i<2 ;i++)
    {
        int x1 = x +rx[i];
        int y1  = y+ry[i];
        if(x1<=0||x1>X||y1<=0||y1>Y)continue;
        int num1 = num ;
        if(arr[x1][y1]=='1')dfs(x1,y1,num,f+1);
        else dfs(x1,y1,num,f);
         if(arr[x1][y1]=='?'&&num>=1)dfs(x1,y1,num-1,f+1);
        
    

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
  

  if(arr[1][1]=='1')dfs(1,1,K,1);
  else dfs(1,1,K,0);
  if(arr[1][1]=='?'&&K>=1)dfs(1,1,K-1,1);
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