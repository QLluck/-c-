#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
// string a[N];
int a[50][50];
set<int> se[N];
int solve()
{
    // int a,b;
    
//    int k;
     int n,m;
     cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x ;
            cin>>x;
            se[i].insert(x);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int num=0;
        
        cout<<num<<'\n';
    }

  
    

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    solve();
}