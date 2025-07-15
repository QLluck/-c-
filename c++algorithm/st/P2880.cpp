#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7;
int arr[N]={0};
pair<int,int> st[N][20];
void init_st(int n)
{
     int k = log(n)/log(2) +1;
     for(int i =1; i<=n;i++)st[i][0].first=arr[i],st[i][0].second=arr[i];

     for(int j =1 ;j <k ;j++)
     {
         for(int i =1;i <= n-(1<<j)+1;i++)
         {
             st[i][j].first = max(st[i][j-1].first,st[i+(1<<(j-1)) ][j-1].first);
             st[i][j].second = min(st[i][j-1].second,st[i+(1<<(j-1)) ][j-1].second);
             
         }
     }
}
int queryma(int l,int r)
{
     int k =  log(r-l+1)/log(2);
     return max(st[l][k].first,st[r-(1<<k)+1][k].first);
}
int querymi(int l,int r)
{
     int k =  log(r-l+1)/log(2);
     return min(st[l][k].second,st[r-(1<<k)+1][k].second);
}

void solve()
{
   int n,q;
   cin>>n>>q;
   for(int i=1; i<=n ;i++)cin>>arr[i];
   init_st(n);
   for(int i =1; i<=q ;i++)
   {
      int l,r ;
      cin>>l>>r;
      cout<<queryma(l,r)-querymi(l,r)<<'\n';

   }
   cout<<'\n';
   

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}