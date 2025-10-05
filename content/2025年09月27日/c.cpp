#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
const int mod = 998244353 ;
int a[N];
int b[N];
void sw(int x,int l,int r)
{
    if(x&1)
    {
        int it = l ;
        for(int i=l ;i<=r ;i+=2)
        {
            b[it]=a[i];
            it++;
        }
        for(int i=l+1 ;i<=r ;i+=2)
        {
            b[it]=a[i];
            it++;
        }

    }
    else 
    {
                int it = l ;
        for(int i=l ;i<=r ;i+=2)
        {
            a[it]=b[i];
            it++;
        }
        for(int i=l+1 ;i<=r ;i+=2)
        {
            a[it]=b[i];
            it++;
        }
    }
}
void dfs()
{
    queue<pair<int ,pii>> que;
    int n = r-l+1;
    
    if(n<=1)return;
    else if(n&1)  
    {
        int mid = n/2 ;
        sw(index,l,r);
        dfs(l,l+mid,index+1);
        dfs(r-mid+1,r,index+1);
    }
    else 
    {
        int mid= n/2;
        sw(index,l,r);
        dfs(l,l+mid-1,index+1);
        dfs(r-mid+1,r,index+1);
    }
}
void solve()
{


 int n;
 cin>>n;
 for(int i=1;i<=n;i++)a[i]=i,b[i]=i;
 dfs(1,n,1);
 for(int i=1;i<=n;i++)cout<<a[i]<<' ';
 cout<<'\n';
 for(int i=1;i<=n;i++)cout<<b[i]<<' ';
 cout<<'\n';


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int sum = 1000000000;
    //  sum = sum*sum;
 
    // cout<<sum+1<<'\n';
    // cout<<N<<'\n';
    int t;
    cin>>t;
    while(t--)
    solve();
}