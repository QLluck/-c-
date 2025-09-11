#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
const int P = 1e9+7;

int pai[N]={0};
int me[N]={0};
vector<int> p ;
// vector<pair<int,int> > xuan[N] ;
int si=0;
int ans =0 ;
int n=0;
int f(int x)
{  if(x>n)return 0;
    //cout<<x<<' '<<( x + (n/x *x ) ) *(n/x)/2<<'\n';

    return   ( x + (n/x *x ) ) *(n/x)/2;
}
void dfs(int d,int num,int sum)
{
     if(d==si)
     {   if(num==0)return;
        if(num&1)ans+=f(sum);
        else ans -=f(sum);
        return;
     }
   dfs(d+1,num+1,sum*p[d]);
   dfs(d+1,num,sum);
      
}


void solve()
{
    // int n;
    cin>>n;
    p.clear();
    ans=0;
    // for(int i=1;i<=10000;i++)xuan[i].clear();
    //  if(n==1)cout<<0<<'\n';
    int sq = sqrt(n);
    int num = n ;
    for(int i=2;i<= sq;i++)
    {
        if(num%i==0)
        {
            p.push_back(i);
             while(num%i==0)num/=i;
        }
        if(i>num)break;
    }
    if(num!=1)p.push_back(num);
  //  p.push_back(1);
     si=p.size();
   dfs(0,0,1);
   ans = (1+n)*n/2 - ans;
   cout<<ans<<'\n';
}

//2 3 5 
// 2 3
// 10
// 1 2 3 4
// 2
//1 2 3 4
//n/2 + n/3 + n/5
// - n/2*3 -n/2*5 -n/3*5
// + n/2*3*5 

//
// 2
// 
// 3 2 1

signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

  //for(int i=1;i<=10;i++)cout<<pai[i]<<' '<<'\n';
//   init();
//   cout<<pai[10]<<'\n';
  int t;
  cin>>t;
  while(t--)
  solve();
// ce();
//    cout<<2*3*5*7*11*13*17*19*23LL<<'\n';

}