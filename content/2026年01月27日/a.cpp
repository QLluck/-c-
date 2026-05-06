#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
int x,y;
const int N = 100+7;
char a[N][N];
int me[N][N];
int rx[4]={0,1,0,-1};
int ry[4] ={1,0,-1,0};
int bfs(int sx,int sy)
{
   queue<PII> que;
   que.push({sx,sy});
   me[sx][sy]=1;
   int flag =1;
   while(que.size())
   {
    int xu = que.front().fi;
    int yu = que.front().se;
    que.pop();
    
    for(int i=0;i<4;i++)
    {
        
        int x1 = xu+rx[i];
        int y1 = yu +ry[i];
        //  cout<<x1<<' '<<y1<<'\n';
        if(x1<0||x1>=x || y1<0||y1>=y||me[x1][y1]||a[x1][y1]=='.')continue;
        me[x1][y1]=1;
       
        if(y1!=yu)flag=0;
        que.push({x1,y1});
    }
   }
  
   return flag;
}
void solve()
{

    for(int i=0;i<x;i++)
    {
        scanf("%s",a[i]);
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)me[i][j]=0;
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(me[i][j])continue;
            else if(a[i][j]=='.')continue;
            else if(a[i][j]=='o')
            { 
                // cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
                int flag = bfs(i,j);
                if(flag)
                {
                    printf("2018\n");
                    return;
                }
            }
        }
    }
    printf("2020\n");
   
  

  

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
     while(scanf("%lld %lld",&x,&y)!=EOF)
    {   
          solve();
    
    }
  
}