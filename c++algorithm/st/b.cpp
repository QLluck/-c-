#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+7;
int arr[N]={0};
int st[N][30]={0};
int gcd(int a ,int b)
{
     if(a>b)swap(a,b);
     while(a)
     {
         int temp = b%a;
         b= a;
         a=temp;
     }
     return b;
}
void init_st(int n)
{
     int k = log(n)/log(2)+1;
     for(int i =1; i<=n; i++)st[i][0]=arr[i];
     for(int j =1; j<k ;j++)
     {
          for(int i =1; i<= n - (1<<j)+1 ;i++)
          {
             st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1)) ][j-1]   );
          }
     }
}

int query(int l,int r)
{    
     int k = log(r-l+1)/log(2);
     //cout<<l<<' '<<r<<'\n';
     return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
void solve()
{
     int n,m;
     cin>>n>>m;
     for(int i =1; i<=n ;i++)cin>>arr[i];
     init_st(n);
     for(int i =1; i<=m;i++)
     {
         int l,r;
         cin>>l>>r;
         if(l==r)cout<<arr[l]<<'\n';
         else 
         cout<<query(l,r)<<'\n';

     }
     


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}