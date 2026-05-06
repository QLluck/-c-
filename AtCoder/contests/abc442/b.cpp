#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N = 2e5+7;
const long double PI = 3.14159265358979323846;
const long double MI = 1e-25;
PII a[N];
int t[N];
int c[N];
    int cnt =0 ;
struct node
{
    long double fi;
    int se;
};
pair<PII,int> b[N];
int me[N];
// int de(double a,double b){return fabs(a-b)< MI;}
// long double at(int x,int y)
// {
//      long double rad = atan2(y,x);
//     long double angle = rad;
//     if(angle>0)angle-=2*PI;
//     angle =-angle;
//     return angle;

// }
int cross(PII a,PII b){return a.fi*b.se - a.se*b.fi;}
bool f(pair<PII,int> aa,pair<PII,int> bb)
{
     PII a=aa.fi;
     PII b =bb.fi;
    int a1 = (a.se>0 || (a.se==0 && a.fi<0));
    int b1 = (b.se>0 || (b.se==0 && b.fi<0));
    if(b1!=a1)return a1<b1;
    return cross(a,b)<0;
}
int cmp(PII a,PII b)
{
     int a1 = (a.se>0 || (a.se==0 && a.fi<0));
    int b1 = (b.se>0 || (b.se==0 && b.fi<0));
    if(a1!=b1)return 0;
    else return cross(a,b)==0;
}
int ans(int l,int r)
{
    int itl=me[l],itr=me[r];
    // cout<<' '<<itr<<' '<<c[itr]<<' '<<itl<<' '<<c[itl]<<'\n';
    if(itr>=itl)return (c[itr]-c[itl-1]);
    else return (c[itr] + c[cnt]-c[itl-1]) ;  
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)me[i]=0,c[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,b[i].fi = a[i],b[i].se=i;
    sort(b+1,b+n+1,f);
    int it =1;
   cnt=0;
    while(it<=n)
    {
        int num=1;
        cnt++;
          while(it<n && cmp(b[it].fi,b[it+1].fi))
          me[b[it].se]=cnt,num++,it++;
          me[b[it].se]=cnt;
          c[cnt]=num;
          it++;
    }
    // for(int i=1;i<=cnt;i++)cout<<c[i]<<' ';
    // cout<<'\n';
    for(int i=1;i<=cnt;i++)c[i]+=c[i-1];
    // for(int i=1;i<=cnt;i++)cout<<c[i]<<' ';
    // cout<<'\n';
    // for(int i=1;i<=n;i++)me[b[i].se]=i;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<ans(l,r)<<'\n';

    }


    
    
     
}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   int t;
   t=1;
//    cin>>t;
   while(t--)solve();

}