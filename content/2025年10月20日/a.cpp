#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
map<int,int>mp;
pii a[N];
pair<pii,int> b[N];
int c[N];
bool cmp(pii a,pii b)
{
     if(a.fi!=b.fi)return a.fi<b.fi;
     else return a.se<b.se;
}
bool cmp1(pair<pii,int> a,pair<pii,int> b)
{
     if(a.fi.fi!=b.fi.fi) return a.fi.fi<b.fi.fi;
     else return a.fi.se<b.fi.se;
}
void solve()
{
   
    mp.clear();
    int n;
    cin>>n;
    int ans =0 ;
    for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,b[i].fi.fi=a[i].fi,b[i].fi.se=a[i].se,b[i].se=i,mp[a[i].fi]++,c[i]=0;
    
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp1);
    // for(int i=1;i<=n;i++)cout<<b[i].fi.fi<<' ';
    // cout<<'\n';
    int it = n;

    int sum = 0 ;
    int maf=  a[n].fi;
    int mas = a[n].se;
    int numf =0;
    int nums= 0 ;
    int ansj = 0 ;
    int itn =0 ;
    while(it>=1)
    {  
        if(maf==a[it].fi)
        {
            numf++;
            if(mas==a[it].se)
            {
                nums++;
            }
            else 
            {
                nums=1;
                mas=a[it].se;
            }
        }
        else 
        {
            numf=1,nums=1;
            maf=  a[it].fi;
            mas = a[it].se;

                ans = max(ans,ansj);
            
            ansj=0;
        }
        int sum1 = numf + min(a[it].se,ans);
        c[it]=sum1;
        ansj=max(ansj,sum1);
        // cout<<a[it].fi<<' '<<it<<' '<<ans<<' '<<sum1<<' '<<numf<<' '<<mas<<'\n';
       it--;     
    
    }

     ans = max(ans,ansj);

    
    cout<<ans<<'\n';
  map<int,int>mp1;
  it =1;
//   for(int i=1;i<=n;i++)cout<<c[i]<<' ';
//   cout<<'\n';
    for(int i=1;i<=n;i++)
    {
         int shen = mp[b[i].fi.fi]-mp1[b[i].fi.fi];
         
         if(ans>=1 &&c[i] >=ans )
         {
            ans--;
            cout<<b[i].se<<' ';
         }
    //  cout<<it<<' '<<shen<<' '<<b[i].fi.se<<'\n';
        mp1[b[i].fi.fi]++;
    }
    cout<<'\n';
    // cout<<(1+2>=1)<<'\n';
    



}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
   
    cin>>t;
    while(t--)
    solve();
}
//1 1 1 2 2 2 3 3 3 4 4 4 4 4 4 4 5 5 5
//                  3 3 3 2 2 2 2 
//
//
//
//
//
