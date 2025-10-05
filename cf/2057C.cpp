#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 3e5+7;
const int mod = 998244353;
int a[N];
void solve(int l,int r)
{
    // int l,r;
    // cin>>l>>r;
    int b1 =0 ;
    int b2 =0 ;
    int f =1;
    for(int i= 31 ;i>=0 ;i--)
    {
        int l1 = (l>>i) &1;
        int r1 = (r>>i)&1;
        if(f==1&&l1==r1)
        { b1+=(r1)?(1LL<<i):0;
            continue;
        }
        else if(f==1) f=2;
        if(f==2)
        {   
            b1+=(1LL<<i);
            break;
        }

    }
    if(b1==r)cout<<r<<' '<<r-1<<' '<<l<<'\n';
    else 
    {
        if(b1-1==l)cout<<b1+1<<' '<<b1<<' '<<l<<'\n';
        else cout<<b1<<' '<<b1-1<<' '<<l<<'\n';
    }

    // int ans =0 ;
    // if(l<b1&&b1<r)ans=b1;
    // else ans=b2;
    // cout<<l<< ' '<<ans<<' '<<r<<'\n';



    

}

void te()
{
    for(int i=1;i<=10000;i++)
    {
        // if(i+1!=solve(i,i+2))
        // { cout<<i<<'\n';
        //     cout<<solve(i,i+2)<<'\n';
        //     break;
        // }
        // cout<<i<<'\n';
    }
    cout<<"YES"<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {int l,r;
        cin>>l>>r;
        solve(l,r);
    }
    // te();
}
