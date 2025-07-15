#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
int arr[N]={0},it;
int st[N][20]={0};

void insert(int x,int flag,int p )
{  
     ll r = 1e9+7;
    x = (ll)(r*p +x +flag) %p ;
          
    
    arr[++it]=x;
    st[it][0]=x;
    int k = log(it)/log(2)+1;
    for(int j=1; j<k ;j++)
    {
        int l= it- (1<<j)+1;
        st[l][j]=max(st[l][j-1],st[l+(1<<(j-1))][j-1]);

    }
}
int query(int len)
{
     int l = it -len+1;
     int k = log(it-l+1)/log(2);
     return max(st[l][k],st[it-(1<<k)+1][k]);
     
}
void solve()
{
    int flag= 0 ;
    int n,p;
    cin>>n>>p;
    for(int i =1; i<= n;i++)
    {
        char o;
         cin>>o;
         if(o=='A')
         {
             int x ;
             cin>>x;


             insert(x,flag,p);
         }
         else 
         {  
             int l ;
             cin>>l;
             flag = query(l);
             cout<<flag<<'\n';
         }
    }


   

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    solve();
}