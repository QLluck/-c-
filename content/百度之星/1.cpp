#include<bits/stdc++.h> 

using namespace std;
#define ll long long
const int  N = 1e3+7 ;
pair<ll ,ll > arr[N]; 
bool cmp(pair< ll , ll > a , pair< ll, ll >b){return a.first + a.second < b.first+b.second ;}
void solve()
{
    ll n,b ; 
    cin>>n>>b;
    for(int i =1; i<=n;i++)
    {
         cin>>arr[i].first>>arr[i].second;
    }
    sort(arr+1,arr+n+1,cmp);
    int ans =0 ; 
    for(int i= 1; i<=n; i++)
    {
         int ma= 0  ; 
         int num = b ;
         num -=  arr[i].first /2  + arr[i].second ;
         if(num<0)continue;
         ma ++;
         for(int j =1; j<=n;j++ )
         {   if(j==i)continue;
             num -=  arr[j].first  + arr[j].second ;
             if(num<0)break;
             ma++;
         }
         ans = max(ma,ans);
    }
    cout<<ans<<'\n';


}
int main( )
{ 
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
    return 0;
} 