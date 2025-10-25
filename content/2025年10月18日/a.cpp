#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6+7;
int a[N];
int me[N]={0};
void solve()
{
    int n,m;
    cin>>n;
    int sum1 =0 ;
    int sum2 = 0;
    for(int i=1;i<=n;i++)
    {   cin>>a[i];
        if(a[i]<=4)sum1+=me[a[i]];
        else sum2++;

    }
    if(n==1)
    {
        cout<<"First\n";
        return;
    }
    cout<<sum1<<' '<<sum2<<'\n';
    if(sum1&1)
    {
        if(sum2&1)cout<<"Second\n";
        else cout<<"First\n"; 
         
       
    }
    else 
    {
       if(sum2&1)cout<<"First\n";
        else cout<<"Second\n"; 
    }
    



}
void te()
{int m;
    cin>>m;
    for(int j=1;j<=m;j++)
{   cout<<"------ "<<j<<'\n';
    for(int i=0;i<=sqrt(j);i++)
    {   if(sqrt(j)==(int)sqrt(j)&&i==0)continue;
         int ans = j-(int)sqrt(j)*(int)sqrt(j) +i*(int)sqrt(j);
         cout<<j-ans<<'\n';
    }
}
for(int i=1;i<m;i++)cout<<me[i]<<' ';

}
void init()
{
    int j = 1;
    me[1]=1;
    me[2]=2;
    me[3]=2;
    me[4]=3;
  int it = 1;
    for(int i=5;i<N;i++)
    {
        // if(i*i>=N)break;
    // int ans ;
    if((int)sqrt(i)==sqrt(i))it++;
    
        me[i]=it;
        
    }
    // for(int i= j*j-1;i>=1;i--)
    // {
    //     if(me[i])me[i]=min(me[i],me[i+1]);
    //     else me[i]=me[i+1];
    // }
}
signed main()
{
   ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
   init();
    //   solve();
te();
}