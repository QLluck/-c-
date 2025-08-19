#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first 
#define se second 

const int N = 200+7;
int a[5][N];
pii ans[10000];
int it;
void print(int n)
{
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
void solve()
{  int n,l,r,k;
    cin>>n>>l>>r>>k;
    if(n&1)
    { cout<<l<<'\n';
        return;
    } 
    if(n<=2)
    {
        cout<<-1<<'\n';
        return ;
    }
    int k1 = 1;
    int tmp =l;
    while(tmp)tmp>>=1,k1<<=1;
    if(k1>r)cout<< -1 <<'\n';
    else 
    {
        if(k>=n-1)cout<<k1<<'\n';
        else cout<<l<<'\n';
    }

   
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
// 110
// 110
//1000
//1000