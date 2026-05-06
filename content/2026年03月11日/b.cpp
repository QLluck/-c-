#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define PII pair<int,int>
const int N =1e3+7 ;
int  a[N][N];
PII b[N];
int c[N];
struct node 
{
    int r,c,h,w;
};
node ans[1000000];
void solve()
{  
    // int n;
    int n,x,y;
    int it =0 ;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)a[i][j]=0;
    a[x][y]=1;
    int l =0 ;
    int x1=x-1,y1=y-1;
    // int mix=1e9,miy=1e9;
    while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        l++;
        it++;
         a[x1][y1]=1;
        ans[it].r=x1,ans[it].c=y1,ans[it].h=l,ans[it].w=l;
        for(int i=1;i<=l;i++)a[x1][y1+i]=1;
        for(int i=1;i<=l;i++)a[x1+i][y1]=1;
        x1--,y1--;
    }
    x1=x+1,y1=y+1;
    while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        l++;
        it++;
        a[x1][y1]=1;
        ans[it].r=x1,ans[it].c=y1,ans[it].h=-l,ans[it].w=-l;
        for(int i=1;i<=l;i++)a[x1][y1-i]=1;
        for(int i=1;i<=l;i++)a[x1-i][y1]=1;
        x1++,y1++;
    }
    x1 =n ,y1 =1;
    while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        // cout<<x1<<' '<<y1<<'\n';
        x1--,y1++;
    }

    x=x1,y=y1;
    x1 = x +1 ,y1=y-1;
        while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        l++;
        it++;
         a[x1][y1]=1;
        ans[it].r=x1,ans[it].c=y1,ans[it].h=-l,ans[it].w=l;
        for(int i=1;i<=l;i++)a[x1][y1+i]=1;
        for(int i=1;i<=l;i++)a[x1-i][y1]=1;
        x1++,y1--;
    }
        x1 =1 ,y1 =n;
    while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        // cout<<x1<<' '<<y1<<'\n';
        x1++,y1--;
    }
    x=x1,y=y1;
    x1=x-1,y1=y+1;
    while(x1>=1 && x1<=n && y1>=1 && y1<=n  && a[x1][y1]!=1)
    {
        l++;
        it++;
         a[x1][y1]=1;
        ans[it].r=x1,ans[it].c=y1,ans[it].h=l,ans[it].w=-l;
        for(int i=1;i<=l;i++)a[x1][y1-i]=1;
        for(int i=1;i<=l;i++)a[x1+i][y1]=1;
        x1--,y1++;
    }

    //     for(int i=1;i<=n;i++)
    //     {
    // for(int j=1;j<=n;j++)
    // {
    //      cout<<a[i][j];
    // }
    // cout<<'\n';
    //     }
    cout<<"Yes"<<'\n';
    cout<<it<<'\n';
    for(int i=1;i<=it;i++)
    {
        cout<<ans[i].r<<' '<<ans[i].c<<' '<<ans[i].h<<' '<<ans[i].w<<'\n';
    }

    



   
   

}
// 
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t =1;
    // cin>>t;
    while(t--)solve();
}