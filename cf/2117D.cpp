#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N]={0};


int me[N]={0};
void solve()
{
   
    int n;

    cin>>n;
    int mi =1e9+7;
    for(int i=1;i<=n;i++)cin>>a[i];
    int d = a[2]-a[1];
    int f =0 ;
    for(int i=3; i<=n;i++)if(a[i]-a[i-1]!=d)f=1;
    if(f)
    {
        cout<<"NO"<<'\n';
        return;
    }
    
    if(d>=0)a[1] -= d ;
    else a[1] = a[1]-  ((-d)*(n)) ;
    if(a[1]>=0&&(a[1]%(n+1)==0))cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
     

        
     

}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}