#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
struct node
{
    int x,y,z;
};
node a[10];
vector<int> t[10];
bool chon()
{
    for(int i=1;i<=8;i++)
    {
        for(int j=i+1;j<=8;j++)
        {
            if(a[i].x==a[j].x&&a[i].y==a[j].y && a[i].z == a[j].z)return 1 ;
        }
    }
    return 0;
}
node p(int i,int j)
{
    node tmp;
    tmp.x= a[i].x-a[j].x;
    tmp.y= a[i].y-a[j].y;
    tmp.z= a[i].z-a[j].z;
    return tmp;
}
bool cui(node a,node b)
{
    if(a.x*b.x + a.y*b.y + a.z*b.z )return 0;
    else return 1;
}
bool dian(int u)
{
    if(t[u].size()!=3)return 0;
    for(int i=0;i<t[u].size();i++)
    {
        int j = (i+1)%3;
        int v1 = t[u][i];
        int v2 = t[u][j];
        if(!cui( p(u,v1 ) ,p(u,v2)   ) )return 0;
    }
    return 1;
}
int ju(int i,int j)
{
    int ans = (a[i].x-a[j].x) *(a[i].x-a[j].x);
    ans+= (a[i].y-a[j].y) *(a[i].y-a[j].y);
    ans+= (a[i].z-a[j].z) *(a[i].z-a[j].z);
    return ans;
}
void solve()
{
  for(int i=1;i<=8;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    if(chon())
    {
        cout<<"NO"<<'\n';
        return;
    }
    for(int h=2;h<=8;h++)
    {
        for(int i=1;i<=8;i++)t[i].clear();
        int sum = ju(1,h);
        for(int i=1;i<=8;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                if(ju(i,j)==sum)
                { t[i].push_back(j);
                 t[j].push_back(i);
                }
            }
        }
        int f =1 ;
        for(int i=1;i<=8;i++)
        {
            if(dian(i)==0)f=0;
        }
        if(f)
        {
            cout<<"YES"<<'\n';
            return;
        }

    }
    cout<<"NO"<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)
    solve();
}