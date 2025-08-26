#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+7;
int a[507][507];
void solve()
{ 
 int n;
 cin>>n;

 int s =(n&1)? n/2+1:n/2;
 //a[n/2][n/2]=0;
 int xl = s;
 int yl = s;
 int xr =s;
 int yr= s;
 a[s][s]=0;
 int it = 0;

 it++;
 for(int i=1;i<n;i++)
 { if(i&1)
    {

    xr++,yr++;
    for(int j=xl; j<xr ;j++)a[j][yr]=it,it++;
    for(int j =yl;j<=yr;j++) a[xr][j]=it,it++;
    }
    else 
    {
        xl--,yl--;
    for(int j=xr; j>xl ;j--)a[j][yl]=it,it++;
    for(int j =yr;j>=yl;j--) a[xl][j]=it,it++;
    
   
    }
//      for(int i=1;i<=n;i++)
//  {
//     for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
//     cout<<'\n';
//  }
 }
 for(int i=1;i<=n;i++)
 {
    for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
    cout<<'\n';
 }

}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}
//0 1 4
//2 3 5
//6 7 8