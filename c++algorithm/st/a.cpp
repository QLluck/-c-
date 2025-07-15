#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7;
int arr[N]={0};
int st[N][20]={0};
void init_st(int n)
{
    int len =log(n)/log(2)+1;
   for(int i =1; i<=n;i++)st[i][0]=arr[i];
   for(int i =1; i<len ;i++)
   {
       for(int j =1; j<= n-(1<<i)+1;j++)
       {
          st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
          //cout<<j<<' '<<i<<' '<<st[j][i]<<'\n';
       }

   }
}
int query(int l,int r)
{
      int len = log(r-l+1)/log(2);
    return max(st[l][len],st[r-(1<<len)+1][len]);


}
void solve()
{ 
    int n,m;
    cin>>n>>m;
    for(int i =1; i<=n ;i++)cin>>arr[i];
    init_st(n);
    for(int i =1;i<=m;i++)
    {
        int l,r ;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}