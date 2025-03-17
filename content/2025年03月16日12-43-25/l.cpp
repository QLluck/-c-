#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long
ll arr[N]={0};
int arr2[N]={0},it;
ll pix[N]={0};
ll n,c,d;
bool cmp(int a,int b){return a>b;}
ll f(ll d ,ll mid)
{
    ll it = min(mid+1,n);
    it = min(it,d);
    ll ans =  (d/(mid+1) )*pix[it];
   
          if(it<=d%(mid+1))ans+=pix[it];
          else ans+=pix[d%(mid+1)];
    

    return ans ;
}

void solve()
{ 
     
     cin>>n>>c>>d;
     for(int i =1; i<=n ;i++)
      cin>>arr[i];
      sort(arr+1,arr+n+1,cmp);
      ll sum = 0 ;
      for(int i =1; i<=n ;i++)
      {
          
          pix[i]=pix[i-1]+arr[i];
          if(i<=d&&pix[i]>=c)
          {
            cout<<"Infinity"<<'\n';
            return ;
          }
    
      }
      if(d*arr[1] <c)
      {
        cout<<"Impossible"<<'\n';
        return ;
      }
      
      ll l= -1 ; 
      ll r = d-1;
      while(l+1!=r)
      {
          ll mid = (l+r)/2;
          if(f(d,mid)>=c)l=mid;
          else r=mid;
         // cout<<mid<<' ' <<f(d,mid)<<'\n';

      }
      cout<<l<<'\n';



  
    
}
int main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
  
   cin>>t ;
   while(t--)
   solve();
}