#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N =2e5+7;
int a[N]={0};

void solve()
{
   int n,m,k;
   cin>>n>>m>>k;
//    for(int i=1; i<=n;i++)cin>>a[i];
   int t = n-m*k;
   int l= 0;
   int r = k-1;
   int it =0 ;
   int num= 0;
   int n1= n/k*m;
   
   for(int i =1;i<=k;i++)
   {
       int j = i ;
       while(j<=n)
       {
        a[j]=num;
        it++;
        if(it>=m+1)it=0,num++;
        
        j+=k;
       }
   }

   for(int i =1; i<=n;i++)cout<<a[i]<<' ';


   cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
       { solve();
       }
}