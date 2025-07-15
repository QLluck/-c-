#include<bits/stdc++.h>
using namespace std ;
const int N =250+7;
int arr[N][N]={0};
pair<int,int> st[N][N][10][10];
void init_st(int n)
{
     for(int i =1; i<=n ;i++)
     for(int j =1  ;j<=n; j++)
      st[i][j][0][0].first=arr[i][j],st[i][j][0][0].second=arr[i][j];
      int k = log(n)/log(2) +1;
    
      for(int g1 = 0; g1<k ;g1++ )
      {
         for(int g2 =0 ;g2<k ;g2++)
         {
            if(g1==0&&g2==0)continue;

         
         for(int i =1 ;i<= n-(1<<g1)+1;i++  )
         {
             for(int j=1; j<= n-(1<<g2)+1 ;j++)
             {
                 if(g1)
                 {
                     st[i][j][g1][g2].first = max(st[i][j][g1-1][g2].first , st[i+(1<<(g1-1) )][j][g1-1][g2].first);
                     st[i][j][g1][g2].second =min(st[i][j][g1-1][g2].second,st[i+(1<<(g1-1))][j][g1-1][g2].second);
                 }
                 else 
                 {
                     st[i][j][g1][g2].first = max(st[i][j][g1][g2-1].first , st[i][j+(1<<(g2-1))][g1][g2-1].first);
                     st[i][j][g1][g2].second =min(st[i][j][g1][g2-1].second,st[i][j+(1<<(g2-1))][g1][g2-1].second);     
                 }
             }
         }
        }
      }
}
int query(int l,int r,int len,int n)
{
    int re =  min(n,r+len-1);
    int le = min(n,l+len-1);

     int k1= log(le -l +1)/log(2);
     int k2= log(re-r+1)/log(2);

     int ma1 = max(st[l][r][k1][k2].first,st[l][re-(1<<k2)+1][k1][k2].first);
     int ma2 = max(st[le-(1<<k1)+1][r][k1][k2].first,st[le-(1<<k1)+1][re-(1<<k2)+1][k1][k2].first);

     int mi1 = min(st[l][r][k1][k2].second,st[l][re-(1<<k2)+1][k1][k2].second);
     int mi2 = min(st[le-(1<<k1)+1][r][k1][k2].second,st[le-(1<<k1)+1][re-(1<<k2)+1][k1][k2].second);

     int ma = max(ma1,ma2);
     int mi = min(mi1,mi2);
    return ma-mi;


}

void solve()
{

   int n,k,q;
   cin>>n>>k>>q;
   for(int i =1;i <=n ;i++)
   for(int j =1; j<=n ;j++)
   cin>>arr[i][j];
  
   
   init_st(n);
   for(int i =1; i<=q ;i++)
   {
     int l,r;
     cin>>l>>r;
     cout<<query(l,r,k,n)<<'\n';
   }


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}