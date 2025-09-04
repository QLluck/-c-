#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2007;
int a[N]={0};
void solve()
{ 

int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
int mi = 1e9+7 ;
 
int al=0,ar=0;
for(int l= 1;l<=n;l++)
{  
   int sum =0 ;

    for(int r= l;r<=n;r++)
    {
        if(a[r]==a[l])continue;
        if(a[r]>a[l])sum++;
        else sum--;
        if(mi>=sum)
        {
            mi=sum;
            al=l;
            ar=r;
        }

    }

}
if(mi>0)cout<<1<<' '<<1<<'\n';
else 
cout<<al<<' '<<ar<<'\n';


}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}
//4 3 3  2 1 
//4 2 3 1 3