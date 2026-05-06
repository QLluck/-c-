#include<bits/stdc++.h>
using namespace std;
// #define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e6+7;
// string a[N];
// int a[50][50];
bitset<N> bi[300];
bitset<N> b;
PII cha[N];
int c[N],cit;
vector<int> t[N];
void solve()
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
            // bi[x][i]=1;
            t[i].push_back(x);
        }
    }
    int q;
    cin>>q;
    cit=0;
   for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cha[i].fi=x,cha[i].se=y;
        c[++cit]=cha[i].fi;
        c[++cit]=cha[i].se;
        // int num=0;
    //    b=bi[x]&bi[y];
    //    num=b.count();
        // cout<<num<<'\n';
    }
    sort(c+1,c+cit+1);
    // cout<<cit<<'\n';
    cit =  unique(c+1,c+cit+1)-c-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0 ;j<t[i].size();j++)
        {
            int v = t[i][j];
            int id = lower_bound(c+1,c+cit+1,v)-c;
            bi[id][i]=1;
        }
    }
       for(int i=1;i<=q;i++)
    {
        // int x,y;
        int x = lower_bound(c+1,c+cit+1,cha[i].fi)-c;
        int y = lower_bound(c+1,c+cit+1,cha[i].se)-c;
        int num=0;
       b=bi[x]&bi[y];
       num=b.count();
        cout<<num<<'\n';
    }


  
    

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    solve();
}