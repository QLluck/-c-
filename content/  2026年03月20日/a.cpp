#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e6+7;
int a[N];
 int n,k;
int f =1 ;
int b[N],it=0;
void dfs(int d ,int sum )
{
    if(sum!=0&&sum%k==0)return;
    if(d>n)
    {  
        // cout<<sum<<'\n';
        for(int i=1;i<d;i++)
        cout<<a[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<k;i++)
    {
        a[d]=i;
        int s1 = sum+i;
        int f=0;
        for(int j=0;j<d;j++)
        {
            s1-=a[j];
            if(s1!=0&&s1%k==0)f=1;
        }
        if(f)continue;
        dfs(d+1,sum+i);
    }
}
void solve(int n,int k)
{
    //   int n,m,q;
     
    //   cin>>n>>k;

    //   dfs(1,0);

    //   f=1;
       if(n>=k)
       {
        cout<<-1<<'\n';
        return;
       }
       int it =2;
       for(int i=1;i<=n;i++)a[i]=1;
       int sum = k-1-n;
       
       while(it<=n && sum>=1)
       {
            int it2 = 1;
            while(b[it2]<=sum)it2++;
            it2--;
            sum-=b[it2];
            for(int i=it,j=1;j<=it2;j++,i++)
            {
                a[i]+=j;
            }
            it+=it2+1;
       }
        sum = 0;
        int z =1 ;
    //    for(int i=2;i<=n;i++)
    //    {
    //     // if(a[i]==1)sum+=k;
    //     // int ma = sum+a[i];
    //        a[i]=sum+a[i];
    //     //    a[i]=min(a[i],ma-z);
    //     //    z+=a[i];

    //    }
    int ans =0 ;
       for(int i=1;i<=n;i++)
       { cout<<a[i]<<' ';
        ans+=a[i];
       }
       cout<<'\n';
    //    cout<<ans<<'\n';

    // }
    //    int sum=0;
    //    for(int i=1;i<=n;i++)
    //    {
    //       cout<<sum+1<<'\n';
    //       sum+=k;
    //    }


  
}
void te()
{
    int sum=0;
    for(int i=1;i<=N && sum<=N ;i++)
    {
        sum+=i;
        b[i]=sum;
    }

}
int check(int n,int k)
{
    int sum =0;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        int s1 = sum;
        for(int j=0 ;j<i;j++)
        {
            s1-=a[j];
            if(s1%k==0)return 0;
        }
    }
    return 1;
}
void test()
{
    int n;
    cin>>n;
    // dfs(1,0);

    for(int i=1;i<=n;i++)
    { 
        // cout<<i<<' '<<n<<'\n';
        solve(i,n);
        // a[14]=14;
        if(check(i,n)==0)cout<<"NO"<<'\n';
    }
}
void test2()
{
    cin>>n>>k;
    dfs(1,0);
}
void solve2()
{
    cin>>n>>k;
    solve(n,k);
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    te();
    test2();
    // test();
    // cin>>t;
    // while(t--)
    // solve2();
}