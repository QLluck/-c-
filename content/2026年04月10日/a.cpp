#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second
const int N = 1e5+7;
PII a[N];
PII b[N];
int itb=0;
int ita=0;
int ans[N];
int f2(int x)
{
    int it =0 ;
    while(x)
    {
        ans[++it]=x%10;
        x/=10;
    }
}

int ch(int a,int b)
{
    int num =0 ;
    for(int i=1;i<=4;i++)
    {
        if( (a%10) == (b%10) )num++;
        a/=10;
        b/=10;
    }
    return num;
}
bool f3(PII a,PII b)
{
    return a.se>b.se;
}
void solve()
{
    int n,s;
    cin>>n;
   map<int,int>mp;
    int ma =0 ;
    int it =1 ;
    itb=0;
    ita=0;
    for(int i=1; i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(mp[x])continue;
        mp[x]=1;

        if(y==0)
        {
            b[++itb].fi=x;
            b[itb].se=y;
        }
        else 
        {
            a[++ita].fi=x;
            a[ita].se=y;
            // ma= max(ma,y);
            if(ma<y)
            {
                it=ita;
                ma=y;
            }
        }
    }
    if(ma==4)
    {
        for(int i=1;i<=ita;i++)
        {
            if(a[i].se==4)
            {
                f2(a[i].fi);
                for(int h=4;h>=1;h--)cout<<ans[h];
                cout<<'\n';
                return;

            }
        }

    }
    else if(ma==0)
    {
        sort(b+1,b+itb+1);
        int num =0;
        for(int i=1;i<=itb;i++)
        {
            if(b[i].fi!=i-1)
            {
                f2(i-1);
            for(int h=4;h>=1;h--)cout<<ans[h];
            cout<<'\n';
            return;
            }
        }
    }
    sort(b+1,b+itb+1);
    sort(a+1,a+ita+1,f3);
    int i =0 ;
    int itn=1;
    while(i<=9999)
   {

        while(itn<=itb &&i<=9999 && i==b[itn].fi )
        {
            i++;
            itn++;
        }
        int f =1;

        for(int j=1;j<=ita;j++)
        {
            if(ch(i,a[j].fi)!=a[j].se)
            {
                f=0;
                break;
            }
        }
        if(f)
        {   f2(i);
            for(int h=4;h>=1;h--)cout<<ans[h];
            cout<<'\n';
            return;
        }
        i++;

   }



  
    

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
//