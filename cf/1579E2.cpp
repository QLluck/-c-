#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n ;
const int N =2e5+7;
int arr[N]={0};
pair<int,int>b[N];
pair<ll,ll> pix[N];
int t[N]={0};
int lowbit(int x){return x&-x;}
void add(int x ,int k)
{
     while(x<=n)
     {
         t[x]+=k;
         x+=lowbit(x);
     }
}
int query(int x )
{
     int res=0;
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
     for(int i =1;i<=n;i++)t[i]=0;
     for(int i =1; i<=n;i++)
     {
         cin>>arr[i];
         b[i].first=arr[i];
         b[i].second=i;
     }
     sort(b+1,b+n+1);
     int it = 0 ;
     map<int,int>mp;
     for(int i =1;i<=n;i++)
     {
         if(mp.count(b[i].first))continue;
         else
         {
            mp[b[i].first]=++it;


         }
     }
     for(int i =1; i<=n;i++)arr[b[i].second]=mp[b[i].first];
     ll ans = 0 ;
     map<int,int> mp2;
     for(int i =1; i<=n;i++)
     {   
        pix[i].first=query(arr[i]);
        pix[i].second=mp2[arr[i]];
        mp2[arr[i]]++;
        add(arr[i],1);
     }
     
     for(int i =1; i<=n;i++)
     {
         ll mi1= (i-1 )-pix[i].first;
         ll mi2 =pix[i].first-pix[i].second;
         ans += min(mi1,mi2);
     }
    //  for(int i =1; i<=n;i++)
    //  {
    //      cout<<arr[i]<<' '<<pix[i].first<<' '<<pix[i].second<<'\n';
    //  }
     cout<<ans<<'\n';
    // cout<<"--------------"<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}