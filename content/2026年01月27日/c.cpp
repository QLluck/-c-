#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
int x,y;
const int N = 1e4+7;
struct node
{
    int x,y;
};
node a[10];
struct node2
{
    int x1,x2,y1,y2;
};
node2 xian[10];
int jud(node2 xian, int x3,int y3)
{
    if(xian.x1==xian.x2)return xian.x1;
    int x1=xian.x1,x2=xian.x2,y1=xian.y1,y2=xian.y2;
    int ans = (x2-x1)*y3 - (y1*(x2-x1)- (y2-y1)*x1);
    if(ans>=0 && (y2-y1)>=0)
    ans = abs(ans/(y2-y1));
    else if(ans<=0&&(y2-y1)<=0)ans=abs(ans/(y2-y1));
    else ans=0;

    return ans;
}
int juu(node2 xian, int x3,int y3)
{
    if(xian.x1==xian.x2)return xian.x1;
    int x1=xian.x1,x2=xian.x2,y1=xian.y1,y2=xian.y2;
    int ans = (x2-x1)*y3 - (y1*(x2-x1)- (y2-y1)*x1);
    if(ans>=0 && (y2-y1)>=0)
    ans = abs(ans +(y2-y1) -1) /(y2-y1);
     else if(ans<=0&&(y2-y1)<=0)
     {
        ans = abs(ans);
        int jia =y2-y1 ;
        jia=abs(jia);
      ans = (ans +jia -1) /(jia);
     }
      else ans=0;


    return ans;
}
void solve()
{

  for(int i=2;i<=3;i++)
{
    int x1,y1,x2;
     scanf("%lld %lld %lld",&x1,&x2,&y1);
    
          a[2*i-1].x=x1,a[2*i-1].y=y1;
          a[2*i].x=x2,a[2*i].y=y1;
    }
    
    int cnt =0 ;
    for(int i=1;i<=2;i++)
    {
        for(int j=3;j<=4;j++)
        {
            xian[++cnt].x1 = a[i].x;
            xian[cnt].y1 = a[i].y;
            xian[cnt].x2 = a[j].x;
            xian[cnt].y2 = a[j].y;
        }
    }
    int mau = -1e18;
    int mad = -1e18;
    int miu = 1e18+7;
    int mid = 1e18+7;
    for(int i=1;i<=4;i++)
    {
        for(int j=5;j<=6;j++)
       {    
         int dd = jud(xian[i],a[j].x,a[j].y);
        int du = juu(xian[i],a[j].x,a[j].y);
        mau = max(du,mau);
        miu = min(du,miu);
        mad = max(dd,mad);
        mid = min(dd,mid);

       }
    }

    int l = miu;
    int r = mad;
    int l1=a[5].x;
    int r1 = a[6].x;
    int flag =0 ;
    if(l<=l1 && (l1<=r))flag=1;
    if(l1<=l &&(l<=r1))flag=1;

    if(flag)printf("Yes\n");
    else printf("No\n");

  

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    int x1,x2,y1;
     while(scanf("%lld %lld %lld",&x1,&x2,&y1)!=EOF)
    {   
          a[1].x=x1,a[1].y=y1;
          a[2].x=x2,a[2].y=y1;
          solve();
    
    }
  
}