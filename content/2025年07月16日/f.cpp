#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e3+7;
const int P =998244353;
const int INF = 1e9+7;
int arr[N][N]={0};
int n;
int x,y;

int rx[4]={0,1,0,-1};
int ry[4]={1,0,-1,0};
void dfs(int sx,int sy ,int f,int d)
{
       if(sx<=0||sx>n||sy<=0||sy>n)return ;
       arr[sx][sy]=d;
       if(arr[sx][sy])
       f = (f+1)%4;
       
       dfs(sx+rx[f],sy+ry[f],f,d+1);
}
void solve()
{  
     

  
   cin>>n;
   if(n&1)
   {  
      
      
     dfs(n/2+1,n/2+1,3,0);
   }
   else 
   {
     
      dfs(n/2,n/2,3,0);
   }
   for(int i =1; i<=n;i++)
   {
     for(int j =1; j<= n;j++)
     {
         cout<<arr[i][j]<<' ';
     }
     cout<<'\n';
   }

    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}