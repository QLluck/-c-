#include <bits/stdc++.h>
using namespace std;
const int N =507;
char arr[N][N] = {0};
int pix[N][N]={0};
void solve()
{
     int n,m,k;
     cin>>n>>m>>k;
     for(int i =1;i<=n;i++)
     {
         for(int j =1; j<=m;j++)cin>>arr[i][j];
     }
     for(int i =1; i<=n;i++)
     {
          for(int j =1; j<=m ;j++)
          {
             pix[i][j]= (arr[i][j]=='g'?1:0) +pix[i-1][j]+pix[i][j-1]-pix[i-1][j-1];
          }
     }
     int flag =0 ;
     int ans = 0 ; 
     int sum = pix[n][m];
     for(int i =1; i<=n;i++)
     {
         for(int j =1; j<=m;j++)
         {
            if(arr[i][j]=='.')
            {
                 int i1 = max(1,i-k+1);
                 int j1 = max(1,j-k+1);
                 int i2 = min(n,i+k-1);
                 int j2 =min(m,j+k-1);

                 int hui = pix[i2][j2]-pix[i1-1][j2]-pix[i2][j1-1]+pix[i1-1][j1-1];

                 ans = max(sum-hui,ans);
            }
         }
     }
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