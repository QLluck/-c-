#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7 ;
const int inf = 1e9+7;
pair<int,int> b[N];
pair<int,int> dis[N];
int arr[N]={0};
bool cmp(pair<int,int>a,pair<int,int>b)
{
     if(a.first<b.first)return 1;
     else if (a.first>b.first)return 0;
     else 
     {
         return a.second<b.second;
     }
}
void solve()
{int n;
    cin>>n;
     for(int i =1 ; i<=n;i++)
     {
        cin>>arr[i];
        b[i].first=arr[i];
        b[i].second=i;
     }
     sort(b+1,b+n+1,cmp);
 
     int l =b[1].second;
     int r = b[1].second;
     for(int i =2;i<=n;i++)
     {
         if(l<=b[i].second&&b[i].second<=r)continue;
         else if(b[i].second<l)
         {
           if( r-l+1 + l-b[i].second >b[i].first ) 
           {
            cout<<0<<'\n';
            return;
           }
           else 
           {
              l=b[i].second;
           }
         }
         else if(r<b[i].second)
         {
            if( r-l+1 + b[i].second-r >b[i].first ) 
            {
             cout<<0<<'\n';
             return;
            }
            else 
            {
               r=b[i].second;
            }
         }
     }
   //  for(int i =1;i<=n;i++)cin>>arr[i];
     l = -inf; 
    r =inf;
    for(int i =1; i<=n;i++)
    {
        int l1 =max(1,i-arr[i]+1);
        int r1=min(n, arr[i]+i-1);
        l=max(l1,l);
        r=min(r1,r); 
    }
   // cout<<l<<' '<<r<<'\n';
    if(r<l)cout<<0<<'\n';
    else cout<<r-l+1<<'\n';
  
    //  for(int i =1 ;i<=n;i++)
    //  {
    //      dis[i].first=b[i].second -b[1].second +1 ;
    //      dis[i].second=b[i].first;
    // }
    // sort(dis+1,dis+n+1);
    


//    for(int i=1 ;i<=n;i++)cout<<dis[i].first<<' ';
//    cout<<'\n';
//     for(int i =1; i<=n;i++)
//     {
//         if(dis[i].first>dis[i].second)
//         {
//             cout<<0<<'\n';
//             return;
//         }
//     }
   // cout<<b[1].first<<'\n';


    



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