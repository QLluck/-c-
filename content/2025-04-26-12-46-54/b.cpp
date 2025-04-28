#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7;
#define ll long long 
int arr[N]={0};
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
ll niNum(deque<int>&que)
{
    ll ans =0;
    for(int i =1; i<=n;i++)t[i]=0;
    for(int i =n-1 ; i>=0;i--)
    {
        add(que[i],1);
        ans+= query(que[i]-1);
    }
    return ans ;
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

    deque<int> que;
    for(int i =1; i<=n;i++)
    {
         if(que.size()==0)que.push_back(arr[i]);
         else if(arr[i]<=que.front())que.push_front(arr[i]);
         else if(arr[i]>que.front())que.push_back(arr[i]);
    }
    ll ans =niNum(que);
//    for(int i =0 ;i<n;i++)cout<<que[i]<<' ';
//    cout<<'\n';
//    cout<<niNum(que)<<'\n';

    que.clear();

    for(int i =1; i<=n;i++)
    {
        if(que.size()==0)que.push_back(arr[i]);
        else if(arr[i]<que.back())que.push_front(arr[i]);
        else if(arr[i]>=que.back())que.push_back(arr[i]);
    }
    ans =min(ans,niNum(que));
    // for(int i =0 ;i<n;i++)cout<<que[i]<<' ';
    // cout<<'\n';
    // cout<<niNum(que)<<'\n';
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