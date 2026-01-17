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

void solve()
{
 
   int a,b,c;
   flag=0;
   cin>>a>>b>>c;


//    cout<<"??"<<'\n';
      if(a==b && b==c && c==a)
    {     
        if(a==0) 
        { for(int i=1;i<=3;i++)ans[i]=1;
            flag=1;
        }
    }
   else if(a>=b&&b>=c)
   { 
    flag=1;
    if(a==b&&c==0)
    {
         ans[1]=a,ans[2]=3*a,ans[3]=2*a;
    }
   else 
   {   ans[1]=a,ans[2]=a+b+c,ans[3]=a+c;
    if(b==0)ans[2]=2*a;
   }

    // f1(a,b,c);
   }
   else if(b>=c&&c>=a)
{flag=1;
      if(c==b&&a==0)
    {
         ans[1]=2*b,ans[2]=b,ans[3]=3*b;
    }
    else 
    {
    ans[1]=b+a,ans[2]=b,ans[3]=b+c+a;
    if(c==0)ans[3]=2*b;
    }
    // f1(a,b,c);
}
else if(c>=a&&a>=b)
{flag=1;
        if(c==a&&b==0)
    {
         ans[1]=3*c,ans[2]=2*c,ans[3]=c;
    }
    else 
    {
    ans[1]=b+a+c,ans[2]=b+c,ans[3]=c;
    if(a==0)ans[1]=2*c;
    }
}
else if(a>c&&c>b)  
{
   flag=1;
        int tmp = c*(a/c);
        tmp+=b;
    if(tmp<=a )tmp+=c;

        ans[1]=a,ans[2]=tmp,ans[3]=c;

}
else if(c>b&&b>a)  
{flag=1;
   
        int tmp = b*(c/b);
        tmp+=a;
    if(tmp<=c )tmp+=b;

        ans[1]=tmp,ans[2]=b,ans[3]=c;

}
else if(b>a&&a>c)  
{flag=1;
   
        int tmp = a*(b/a);
        tmp+=c;
    if(tmp<=b )tmp+=a;

        ans[1]=a,ans[2]=b,ans[3]=tmp;

}

for(int i=1;i<=3;i++)
{ if(ans[i]>INF)
  {  cout<<"NO"<<'\n';
    return;
  }
}

if(flag==1)
{
    cout<<"YES"<<'\n';
    for(int i=1;i<=3;i++)cout<<ans[i]<<' ';
    cout<<'\n';
}
else cout<<"NO"<<'\n';



   

    
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
        solve();
        // te();
    }
}