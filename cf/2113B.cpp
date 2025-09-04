#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
#define pii pair<int,int >
#define fi first 
#define se second
#define int long long
pii a[N];

void solve()
{
   
   int n,m,c,d;

   cin>>n>>m>>c>>d;
   cin>>a[1].fi>>a[1].se>>a[3].fi>>a[3].se;
   a[2].fi = a[1].fi + c ;
   a[2].se = a[1].se +d;
   a[4].fi = a[3].fi + c ;
   a[4].se = a[3].se +d;
//    for(int i=1;i<=4;i++)
//    {
//             a[i].fi = min(a[i].fi,n);
//             a[i].se = min(a[i].se,m);
//             a[i].fi  = max(a[i].fi,0LL);
//             a[i].se = max(a[i].se,0LL);
//    }
   int x1 = a[1].fi - a[4].fi;
   int x2 = a[2].fi - a[3].fi ;
   int y1 = a[1].se - a[4].se;
   int y2 = a[2].se - a[3].se ;

    int cay = min(abs(y1),abs(y2));
    int cax = min(abs(x1),abs(x2));
   //cout<<x1 << ' '<<x2<<' '<<y1<<' '<<y2<<' '<<cax<< ' ' << cay<<'\n';
   if(x1*x2<0)
   {   //if(cay==0)cout<<"Yes"<<'\n';
       if(cay%d==0)cout<<"Yes"<<'\n';
       else cout<<"No"<<'\n';
   } 
   else if(y1*y2<0)
   {
       
       if(cax%c==0)cout<<"Yes"<<'\n';
       else cout<<"No"<<'\n';
   } 
   else 
   {  // if(cax==0||cay==0)cout<<"Yes"<<'\n';
       if((cay%d==0)||(cax%c==0))cout<<"Yes"<<'\n';
       else cout<<"No"<<'\n';
   }

  


}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}