#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
int arr[N]={0};
ll pix[N]={0};
pair<int,int> b[N];
int n;
int t[N]={0};
int lowbit(int x ){return x&-x;}
void add(int x ,int k)
{
     while(x<=n)
     {
         t[x]+=k;
         x+=lowbit(x);
     }
}
int query(int x )
{int res=0;
     while(x)
     {
         res+=t[x];
         x-=lowbit(x);
     }
     return res;
}

void solve()
{
   
   cin>>n;
   for(int i =1; i<=n;i++)
    { cin>>arr[i];
      b[i].first=arr[i];
      b[i].second=i;
    }
    sort(b+1,b+n+1);
 
    map<int,int> mp;
    int it = 0 ;
    for(int i =1; i<=n;i++)
    {
         if(mp.count(b[i].first))
         {
             b[i].first=mp[b[i].first];
         }
         else 
         {  
             mp[b[i].first]=++it;
             b[i].first=it;

         }
    }
    for(int i =1;i<=n;i++)
    {
         arr[b[i].second]=b[i].first;
    }

    for(int i =1; i<=n;i++)t[i]=0;
    for(int i =1 ; i<=n;i++)
    {
        pix[i]= query(arr[i]) + pix[i-1];
        add(arr[i],1);
    }
    ll zn = (ll)n*(n-1)/2 - pix[n];
    ll ans = 1e18+7;
    for(int i =2; i<=n;i++)
    {
         ll dn = (ll)i *(i-1)/2 -pix[i];
         ll diaon = pix[i];
         ll mi = min(zn,zn-dn+diaon);
       ans =min(mi,ans);
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