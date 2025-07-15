#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7;
int arr[N]={0};
ll  pix[N]={0};
void solve()
{
     map<ll,int >mp;
     ll n,s,x;
     cin>>n>>s>>x;
     for(int i=1; i<=n;i++)
     {
        cin>>arr[i];
        pix[i]=pix[i-1]+arr[i];
     }
     ll ans =0; 
     int it =1  ;
     for(int i =1;i<=n;i++)
     {
          //mp[pix[i]]++;
          if(arr[i]>x)
          { mp.clear();
            it=i+1;
          }
          else if(arr[i]==x)
          {
            while(it<=i) 
            { mp[pix[it-1]]++;
                it++;

            }
          }

          ans +=mp[pix[i]-s];
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