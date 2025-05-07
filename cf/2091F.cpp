#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int P =998244353;
const int N =2e3+7;
ll pix[N][N]={0};
char arr[N][N]={0};
ll sum[N][N]={0};
int n,m;
void print()
{
    for(int i =1; i<=n;i++)
    {
         for(int j=1; j<=m;j++)
         {
            cout<<sum[i][j]<<' ';
            
         }
         cout<<'\n';
    }
}
void solve()
{  int d;
    cin>>n>>m>>d;
    double r1 = sqrt(d*d-1);
    int r = round(r1);
    cout<<"r "<<r<<'\n';
    for(int i =1; i<=n;i++)
    {
         for(int j =1; j<=m;j++)
         {
             cin>>arr[i][j];
             sum[i][j]=0;
             pix[i][j]=0;
             
         }
    }
    for(int i =1; i<=m;i++)
     { pix[n+1][i]=0;
       if(arr[n][i]=='X') sum[n][i]=1;
     }
    for(int i =n ;i>=1 ;i--)
    {

       // for(int j = 1; j<=m;j++)pix[i][j]=sum[i][j]+pix[i][j-1];
        for(int j =1; j<=m;j++)
        {
             if(arr[i][j]=='#')continue;
              int l = max(1,j-r);
              int r = min(m,j+r);//待定
              
              sum[i][j] += pix[i+1][r]-pix[i+1][l-1];
              sum[i][j]%=P;
             
        }
        cout<<"1-------------"<<'\n';
      print();
   

        for(int j = 1; j<=m;j++)
         { pix[i][j]=sum[i][j]+pix[i][j-1];
            pix[i][j]%=P;
         }
        for(int j =1;j<=m;j++)
        {    if(arr[i][j]=='#')continue;
            int l1= max(1,j-d);
            int r1 = min(m,j+d);
            sum[i][j] += pix[i][r1]-pix[i][l1-1]-sum[i][j] ;
            sum[i][j]%=P;
        }
        cout<<"2-------------"<<'\n';
       print();
        cout<<"---------"<<'\n';
         

    }
    ll ans= 0 ;
    print();
    for(int i=1; i<=m;i++)
    {
         ans= (ans +sum[1][i])%P;
    }
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