#include<bits/stdc++.h> 

using namespace std;
#define int long long
void solve()
{int l,r;
    cin>>l>>r;
    if(l==r)
    {
        if(l==1)cout<<0<<'\n';
        else cout<<"infty"<<'\n';
        return;
    }
    int d = (r-l);
    int it =2;
    int l1 = l+d  ;
    int r1 = 2*l; 
    int ans = l-1;

    // while(l1<r1-1)
    // {  //cout<<l1<<' '<<r1<<'\n';
    //     ans += r1-l1-1; 
    //     l1=r1+it*d;
    //     r1+=l;
    //     it++;
    // }
    int x = (l-1)/d ;
    if(x*d>=l-1)x--;
    int ans2 =0 ; 
    
     if(x>=0)ans2  = ((x+1)*l -x-x*(x+1)*d/2 )-1;
     else ans2 = l-1;
   // else ans2 = l-1;
    //cout<<x<<'\n';
  cout<<ans2<<'\n';
    //cout<<ans<<'\n';

    
}
signed main( )
{ ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
int t;
cin>>t;
while(t--)
solve();
    return 0;
}
// (x+1)*a -1 = x *a + x*d a-1 = x*d;  x  = (a-1)/d ;x if(x>=1) sum =  mi-1 + ( (x+1) *mi -2*x +x*(x-1)*d/2     )