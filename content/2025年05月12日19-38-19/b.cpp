#include<bits/stdc++.h>
const int N =1e6+7;
using namespace std ;
#define ll long long 
int arr[N]={0};
int me[N]={0};
struct node
{
    int num ,it;
};
node b[N]={0};
bool cnt(node a,node b)
{
     if(a.num<b.num)return 1;
     else if(a.num>b.num)return 0;
     else 
     {
         return a.it<b.it;
     }
}
void solve()
{

   int n;
   cin>>n;
   for(int i=1; i<=n;i++)
   {
      cin>>arr[i];
      b[i].num=arr[i];
      b[i].it=i;
   }
   sort(b+1,b+n+1,cnt);
   ll l = n&1? n/2+1 : n/2;

   ll ans= 0 ;
   for(int len =1; len<=n; )
   {    
    
      if(me[len])
    {
        len++;
        ans++;
        continue;
    }
    for(int i =1; i<=n;i++)
{
       
    
       
         ll l1 = min(i,b[i].it);
        ll r1 = max(b[i].it,i);
        while((l1/len * len  >= l1 || l1/len * len + len < r1 )&&len<=n )
        {  len++;      
        }
        if(len>n)break;       
        cout<<l1<< ' '<<r1<<' '<<len<<'\n';
       
    
  if(i==n)
  { ans++;
    
    for(int j=1; j<=n+1;j++)
    {
         if(j*len>n)
         {len++;
           break;
          }
         me[j*len]=1;
    }
   
  }

   }
}

cout<<ans<<'\n';

}


int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
  solve();
}