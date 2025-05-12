#include<bits/stdc++.h>
const int N =5e5+7;
using namespace std ;
#define ll long long 
ll  arr[N]={0};
struct node
{
     int l,r ;
     ll num;
};
node dix[N];
bool cnt(node a,node b){return a.num<b.num;}

void solve()
{  int n,k;
    cin>>n>>k;
    for(int i =1; i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    int  l =1; 
    int r = 1; 
    map<int,int >mp;
    map<int,int>mp2;
    priority_queue<int>que;
    ll ans = 1e18+7;
    while(r<k)
    {     int num = (arr[r+1]-arr[r]);
        que.push(  -num);
        mp[num]++;
    

        r++;
    }
    ans = min(ans, ( (arr[r]-arr[l])*(-que.top()) ));
    while(r<n)
    {
        int num = (arr[r+1]-arr[r]);
        que.push(  -num);
        mp[num]++;

         int dnum=arr[l+1]-arr[l];
         mp[dnum]--;
         mp2[dnum]++;
         while(mp2[-que.top()])
         {
            mp2[-que.top()]--;
            que.pop();
         }
    
        r++;
        l++;
        ans = min(ans, ( (arr[r]-arr[l])*(-que.top()) ));
    }
     
    //cout<<ma<<'\n';
    
    cout<<ans<<'\n';
   

}

int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

  solve();
}