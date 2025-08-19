#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
int a[N];
int pix[N];
int ans[N],it;
void solve()
{

  int n,s;
  cin>>n>>s;
  int l = s; 
  int r = s;
 
  for(int i=1;i<=n;i++)
  {
    char c;
    cin>>c;
    pix[i]=0;
    if(c=='#')pix[i]++;
  }
    while(l>=1&&pix[l]==0)l--;
    while(r<=n&&pix[r]==0)r++;
    int ans =1e9+7 ;
    if(l==0&&r==n+1)ans=1;
    else if(l==0)
    {
        ans = min(s-1,n-r+1)+1;
    }
    else if(r==n+1)ans =min(n-s,l)+1;
    else 
    {
        int l1 = min(s-1,n-r+1);
        int r1 = min(n-s,l) ;
        ans =max(l1,r1)+1;
    }
  cout<<ans<<'\n';
  

    



    
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
