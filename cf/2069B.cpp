#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+7;
int a[N][N]={0};
int n,m;
int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
int mp[500007];
int mpk[500007],it;
int check(int x,int y,int w)
{
    for(int i=0;i<4; i++)
    {
        int x1 = x+rx[i];
        int y1 = y +ry[i];
        if(x1<=0||x1>n||y1<=0||y1>m)continue;
        if(a[x1][y1]==w)return 1;

    }
    return 0;
}
int solve()

{cin>>n>>m;
    it= 0;
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=m;j++ )cin>>a[i][j];
    }
    for(int i=0;i<=n*m;i++)mp[i]=0;
    int f= 0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1 ;j<=m;j++)
        {
            if(mp[a[i][j]]==2)continue;
            //if(mp[a[i][j]]==0)mp[a[i][j]]++;
             if(mp[a[i][j]]==1)
            {  if(check(i,j,a[i][j]))
                f=1,mp[a[i][j]]=2;
            }
            else mp[a[i][j]]=1,mpk[++it]=a[i][j];


        }
    }
    int ans =0 ;
    int num =0 ;
   for(int i=1;i<=it;i++)ans+=mp[mpk[i]];
    if(it==1)cout<<0<<'\n';
    else if(f)cout<<ans-2<<'\n';
    else cout<<ans-1<<'\n';


}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}