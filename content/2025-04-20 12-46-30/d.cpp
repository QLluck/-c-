#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7 ;
int n;
int m;
int xiu[N]={0};
int pix[N]={0};
struct node
{
     int l,r ;
     int num ;
     
};
node arr[N];
int f(int mid)
{
     for(int i =1; i<=n;i++)pix[i]=0;
     for(int i =1; i<=mid;i++)pix[xiu[i]]=1;
     for(int i =1; i<=n;i++)
     {
         pix[i]=pix[i]+pix[i-1];
     }
     for(int i =1;i<=m;i++)
     {
        if(pix[arr[i].r]-pix[arr[i].l-1]>=arr[i].num)return 0;
     }
     return 1;
}
void solve()
{
     
     cin>>n>>m;
     for(int i =1; i<=m ;i++)
     {
         int l,r ;
         cin>>l>>r;
         int num = (r-l+1)/2+1;
         arr[i].l=l;
         arr[i].r=r;
         arr[i].num=num;
     }
     int q ;
     cin>>q;
      for(int i=1; i<=q; i++)cin>>xiu[i];
      int l = 0 ; 
      int r = q+1;
      while(l+1!=r)
      {
         int m = (l+r)>>1;
         if(f(m))l=m;
         else r=m ;
      }
      if(r<=q)
      cout<<r<<'\n';
      else cout<<-1<<'\n';
    



}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    
    int t; 
   // cout<<"YES"<<'\n';
    cin>>t;
    while(t--)
    solve();
}