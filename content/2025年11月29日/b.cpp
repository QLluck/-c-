#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6+7;

void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a==x || b==y)
    {
        if(a==x && b==y)cout<<"Yes"<<'\n';
        else 
        {
            if(b==y)
            {
                
                while(x || a )
                {
                    int nx = x%2;
                    int na = a%2;
                    if(na==0 && nx==1)
                    {
                        cout<<"No"<<'\n';
                        return;
                    } 
                    x>>=1;
                    a>>=1;
                }
                cout<<"Yes"<<'\n';
            }
            else if(a==x)
            {
                while(y || b )
                {
                    int ny = y%2;
                    int nb = b%2;
                    if(nb==1 && ny==0)
                    {
                        cout<<"No"<<'\n';
                        return;
                    } 
                    y>>=1;
                    b>>=1;
                }
                cout<<"Yes"<<'\n';
            }
        }
    }
    else cout<<"No"<<'\n';
   
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // pri();
    int t;
    cin>>t;
    while(t--)
    solve();
    // te();
}
