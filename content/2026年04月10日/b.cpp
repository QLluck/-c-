#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second
const int N = 1e5+7;
PII a[N];
PII b[N];
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
int f(string &s)
{
   int res =0;
   for(int i=0;i<s.size();i++)
   {
    res*=10;
    res+=s[i]-'0';

   }
   return res;
}
bool f3(PII a, PII b){return a.se>b.se;}
map<int,int>mp;
void solve()
{
    int n;
    cin>>n;
    mp.clear();

    int ma =0 ;
    int it =0 ;
    int ita=0;
    int itb=0;
    for(int i=1; i<=n;i++)
    {
        int x,y;
        string s;
        cin>>s>>y;
        // cin>>y;
        x = f(s);
        if(mp[x])continue;
        else mp[x]=1;
        a[++ita].fi=x;
        a[ita].se=y;
        if(y!=0)b[++itb].fi=x,b[itb].se=y;
        if(ma<a[ita].fi)
        {
            it=ita;
            ma=a[ita].se;

        }
    }
     sort(a+1,a+ita+1);
    sort(b+1,b+itb+1,f3);
    if(ma==4)
    {
        f2(a[it].fi);
         for(int h=4;h>=1;h--)cout<<ans[h];
            cout<<'\n';
            return;
    }
    else if(ma==0)
    {
                for(int i=1;i<=ita;i++)
        {
            if(a[ita].fi!=i-1)
            {
                f2(i-1);
            for(int h=4;h>=1;h--)cout<<ans[h];
            cout<<'\n';
            return;
            }
        }
    }
   
   for(int i=0;i<=9999;i++)
   {
    if(mp[i])continue;
        int f =1;
        // if(f==0)continue;
        for(int j=1;j<=itb;j++)
        {
            if(ch(i,b[j].fi)!=b[j].se)
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