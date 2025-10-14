#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 5e5+7;
pii a[N];
bool cmp(pii a,pii b)
{
    if(a.fi!=b.fi)return a.fi<b.fi;
    else return a.se<b.se;
}
void solve()
{
 
int n,k;
cin>>n;
int f= 0;
int n1 = 0;
for(int i=1;i<=n;i++)
{ cin>>a[i].fi;
    a[i].se=i;
   
    a[i].fi = a[i].fi-i;
    if(a[i].fi<0)f=1;
    
    n1+=a[i].fi;
}
// for(int i=1;i<=n;i++)
// {
//     cout<<a[i].fi<<' '<<a[i].se<<'\n';
// }
if(f)
{
    cout<<-1<<'\n';
    return;
}

sort(a+1,a+n+1,cmp);
int ma =0 ;
int l = 0;
int it=1;
int ans =n;
int ma0=0;
while(it<=n)
{
int l1 = 0;
int ma1 = 0;
int num=0;
while(it+1<=n&&a[it].fi==a[it+1].fi)
   { num++;
   // cout<<"---------"<<'\n';
    //cout<<it<<' '<<' '<<a[it].fi<<' '<<a[it].se<<' '<<l<<' '<<ans<<' '<<max(0LL,a[it].fi-ma0)<<' '<<ma0<<'\n';

    if(a[it].se<l)ans+=a[it].fi-ma,ma0+=a[it].fi-ma;
    else {  ans+= max(0LL,a[it].fi-ma0);
    //  cout<<it<<' '<<a[it].fi<<' '<<l<<' '<<ans<<'\n';
    
    l1=max(a[it].se,l1);
    ma1 =max(a[it].fi,ma1);
    }
    it++;
   
   }
   if(it<=n)
   {
    num++;
    //cout<<it<<' '<<' '<<a[it].fi<<' '<<a[it].se<<' '<<l<<' '<<ans<<'\n';
  //  cout<<it<<' '<<' '<<a[it].fi<<' '<<a[it].se<<' '<<l<<' '<<ans<<' '<<max(0LL,a[it].fi-ma0)<<' '<<ma0<<' '<<ma<<'\n';
    if(a[it].se<l)ans+=a[it].fi-ma,ma0+=a[it].fi-ma;
    else{ ans+= max(0LL,a[it].fi-ma0);
    l1=max(a[it].se,l1);
    ma1 =max(a[it].fi,ma1);
    
    }

    // ans+=a[it].fi-ma;
    it++;
   }
   
   l =max(l1,l);
   ma=max(ma,ma1);
//    it++;

}
cout<<ans<<'\n';




// cout<<ans<<'\n';


}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}