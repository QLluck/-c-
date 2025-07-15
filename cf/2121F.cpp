#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =2e5+7;

int arr[N]={0};
ll pix[N]={0};
int st[N][33]={0};
int me[N]={0};
void init_st(int n)
{
     int len = log(n)/log(2)+1;
     for(int i= 1; i<=n;i++)st[i][0]=arr[i];

     for(int j =1 ; j<len ;j++)
     {
         for(int i =1; i <=n-(1<<j)+1 ; i++)
         {
             st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
         }
     }
}
int query(int l,int r)
{ 
     int k = log(r-l+1)/log(2);
    // cout<<l<<' '<<r<<'\n';
     // cout<<"YES4"<<'\n';
      int ans= max(st[l][k],st[r-(1<<k)+1][k]);
     // cout<<"YES5"<<'\n';
     return ans;
}
stack<int> sta;
void solve()
{
    ll n,s,x;
    cin>>n>>s>>x;

    for(int i =1; i<=n; i++)cin>>arr[i];
    while(sta.size())sta.pop();
    for(int i =1; i<=n;i++)
    {     if(arr[i]>=x)sta.push(i);

         if(sta.size()&&arr[sta.top()]<=x)me[i]=sta.top();
         else me[i]=0;
    }
    init_st(n);
    map<ll ,vector<int> >mp;
    ll ans =0 ;
    mp[0].push_back(0);
    for(int i =1; i<=n;i++)
    {
         pix[i]=pix[i-1]+arr[i];
         //cout<<"YES1"<<'\n';
        ll k = pix[i]-s ;
        //  if(k==0&&query(1,n)==x)
        //  {
        //     ans++;
            
        //  }
         //二分
         
         if(mp[k].size()&&me[i]!=0)
         {   //cout<<"YES2"<<'\n';
             vector<int>& v =mp[k];
             int len = v.size();
             int l = -1 ;
             int r = len ;
             while(l+1<r)
             {// cout<<"YES3"<<'\n';
                int mid = (l+r)>>1;
                int it = v[mid]+1;
                if(it<me[i])l=mid;
                else r =mid;
             }
            if( r==0&&v[r]+1>me[i] );
            else
            {
              l = -1 ;
              
             while(l+1<r)
             {// cout<<"YES3"<<'\n';
                int mid = (l+r)>>1;
                int it = v[mid]+1;
                if(query(it,i)!=x)l=mid;
                else r =mid;
             }
             int sum = len-r;
             ans = ans+ sum;
            }

         }


         if(mp[pix[i]].size()==0)mp[pix[i]].push_back(i);
         else mp[pix[i]].push_back(i);


        

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