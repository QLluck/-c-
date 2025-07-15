#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
const int INF = 1e9+7;
int arr[N] = {0};
int f[N]={0};
int gcd(int a ,int b)
{
     if(a>b)swap(a,b);
     while(a)
     {
         int temp = b%a ;
         b =a ;
         a = temp;
     }
     return b;
}
void solve()
{
     int n;
     scanf("%d",&n);
     int k = 0 ;
    
     for(int i =1; i<=n;i++)
     {  scanf("%d",&arr[i]);
        k = gcd(k,arr[i]);
     }
     int ma =0 ;
     for(int i =1; i<=n;i++)
     {
         arr[i]/=k;
         ma = max(arr[i],ma);
     }
     for(int i =1; i<=ma ;i++)
     {
         f[i]=INF;
     }
     for(int i =1; i<=n;i++)f[arr[i]]=0;
   if(f[1]!=0)
   {
     for(int i =ma ;i>=1 ;i--)
     {    if(f[i]==INF)continue;

        for(int j=1; j<=n;j++)
        {
            int x = gcd(arr[j],i);
            if(f[x]>f[i]+1)
            {
                f[x]=f[i]+1;
            }
        }
     }
    }
    int ans = max(f[1]-1,0);
    for(int i =1; i<=n ;i++)
    {
         if(arr[i]>1)ans++;
    }
   printf("%d\n",ans);
}
int main()
{
   // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--)
    solve();
}