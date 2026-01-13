#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int me[N];
PII ans[N];
int it = 0;
int solve(int n,int k)
{
    //  int n,k;
    //  cin>>n>>k;
     if(k&1)
     {
        for(int i=1;i<=k;i++)cout<<n<<' ';
        cout<<'\n';
     }
     else 
     {
        for(int i=1;i<=k-2;i++)cout<<n<<' ';
        int duo = (k-2)*n;
        int n1 =0 ;
        int y= n;
        int n2 =0 ;
        while(y)y>>=1,n1++;
        int f= 1;
        for(int i=n1-2 ; i>=0 ;i--)
        {
            // cout<<f<<' '<<((n>>i)&1)<<' '<<n2<<' '<<n<<'\n';
            if(f&& ((n>>i) &1 )==0 )continue;
            else if(f&& ((n>>i)&1) ==1 ) f=0, n-= (1LL<<i) ,n2+=(1LL<<i);
            else if(f==0 &&((n>>i)&1 )==1 )continue;
            else if(f==0 && ((n>>i)&1 )==0 ) n2+=(1LL<<i),n+=(1LL<<i);
        }

        cout<<n2<<' '<<n<<' ';
        return n2 +n +duo ;
        cout<<'\n';
     }
     return 0;
}
int ma = 0 ;
void dfs(int n,int k,int i,int index)
{
     if(index>k)
     {
        int sum =0 ;
        for(int i=1;i<=k;i++)sum+=a[i];
        int xo = 0;
        for(int i=1;i<=k;i++)xo^=a[i];
        if(sum>=ma && n==xo )
        {
            ma= sum;
            for(int j=1 ;j<=k;j++)cout<<a[j]<<' ';
            cout<<sum;
            cout<<'\n';
        }
        return ;
     }
     for(int j=i;j<=n;j++)
     {
         a[index]=j;
         dfs(n,k,j,index+1);
     }
     
}
int te(int n,int k)
{
     
    //  cin>>n;
     ma =0 ;
     dfs(n,k,0,1);
     return ma ;
    
}
void  dui()
{
    // for(int i=1;i<=1000;i++)
    // {   
       int s1 = te(30,4);
       int s2 = solve(30,4);
       cout<<'\n';
         if(s1!=s2)
         {
           
            cout<<s1<<' '<<s2<<' '<<30<<'\n';
         }
    // }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t=1;
    // cin >> t;
    //14
    
    while (t--)
    dui();
        // solve();
        // te();

    // printb(2);
}
// 4 3 3  2 15
// 4 2 3 1 3