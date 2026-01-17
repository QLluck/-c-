#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+7;
const int mod = 998244353;
const int INF = 1e18 ;
int ar[N];
int ans[10] ,flag;
  int a,b,c;
  int flag2=0;
void dfs(int d,int n,int a,int b,int c)
{  
     if(flag2)return;
    if(d>n)
    {
        if(ar[1]%ar[2]==a && ar[2]%ar[3]==b && ar[3]%ar[1]==c)
        { 
            cout<<ar[1]<<' '<<ar[2]<<' '<<ar[3]<<'\n';
            if(ar[1]==a || ar[2]==b|| ar[3]==c)
            {
                cout<<"YES"<<'\n';

            }
            flag2=1;
           
        } 
        return;
    }
    for(int i=1 ;i<=100 ;i++ )
    {
        ar[d]=i;
        dfs(d+1,n,a,b,c);
    }
}
void te()
{
    for(int i=0;i<=20;i++)
       for(int j= 0 ;j<=20;j++)
       for(int z = 0 ;z<=20 ;z++)
    { flag2=0;
        dfs(1,3,i,j,z);
    }
}
void solve()
{
   int a,b,c;
   cin>>a>>b>>c;

  flag=0;
     if(a==b && b==c && c==a)
    {     
        if(a==0) 
        { for(int i=1;i<=3;i++)ans[i]=1;
            flag=1;
        }
    }
    else if(a==0&&b==0 &&c!=0)
    {
        if(c<=(INF/2))
        {
            flag=1;
            ans[1]=2*c;
            ans[2]=2*c;
            ans[3]=c;
        }
    }
    else if(a==0&&b!=0 &&c==0)
    {
        if(b<=(INF/2))
        {
            flag=1;
            ans[1]=2*b;
            ans[2]= b;
            ans[3]=2*b;
        }
    }
    else if(a!=0&&b==0 &&c==0)
    {
        if(a<=(INF/2))
        {
            flag=1;
            ans[1]=a;
            ans[2]=2*a;
            ans[3]=2*a;
        }
    }

    else if(a==b&&a!=0 &&c>a)
    {
        if(c+2*a <=INF)
        {
            flag=1;
            ans[1]=c+2*a;
            ans[2]=c+a;
            ans[3]=c;
        }
    }
    else if(a==c&&a!=0 &&b>a)
    {
        if(b+2*a <=INF)
        {
            flag=1;
            ans[1]=b+a;
            ans[2]=b;
            ans[3]=b+2*a;
        }
    }
    else if(c==b&&b!=0 &&a>b)
    {
        if(a+2*b <=INF)
        {
            flag=1;
            ans[1]=a;
            ans[2]=a+2*b;
            ans[3]=a+b;
        }
    }



   
    else if(a==b&&c==0&&a!=0)
    {
        if(a+2*a <=INF)
        {
            flag=1;
            ans[1]=a;
            ans[2]=3*a;
            ans[3]=2*a;
        }
    }
    else if(a==c&&b==0&&a!=0)
    {
        if(3*c <=INF)
        {
            flag=1;
            ans[1]=3*c;
            ans[2]=2*c;
            ans[3]=c;
        }
    }
    else if(c==b&&a==0&&b!=0)
    {
        if( 3*b <=INF)
        {
            flag=1;
            ans[1]=2*b;
            ans[2]=b;
            ans[3]=3*b;
        }
    }


    else if(a==c&&a!=0&&b!=0 && a>b)
    {
        if( (2*a +b ) <=INF)
        {
            flag=1;
            ans[1]=2*a+b;
            ans[2]=a+b ;
            ans[3]=c;
        }
    }
    else if(b==c&&b!=0&&a!=0 && b>a)
    {
        if( (2*b +a ) <=INF)
        {
            flag=1;
            ans[1]=b+a;
            ans[2]=b ;
            ans[3]=2*b+a;
        }
    }

    else if(a<b&&b<c)
{
       if( (2*b +a ) <=INF)
        {
            flag=1;
            ans[1]=b+a;
            ans[2]=b ;
            ans[3]=c;
        }
}
    




   

    
}





signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // te();
    t =1;
    cin>>t;
    while(t--)
    { 
        // flag2=0;
        te();
    }
}