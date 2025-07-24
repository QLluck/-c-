#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define int long long
#define fi first
#define se second
const int INF = 1e18+7;
const int N =2e5+7;
const int P =998244353;
int fan= 1;
int po(int a,int b)
{
     int res= 1;
     while(b)
     {
        if(b&1) res =res*a%P ;
        b>>=1;
        a=a*a%P;
     }
     return res %P;
}
vector<int > t[N];
map<pair<int,int>,int > mp;
map<pair<int,int> ,int >mp2;
struct node
{
    int l,r,p,fa;
};
queue<node> que;
int n,m;
int ans =0 ;
void bfs(int l ,int r,int p)
{
     que.push({l,r,p,(1-p+P)%P});
     while(que.size())
     {
           node u = que.front();
           que.pop();
           if(u.r==n)
           {
            ans =( ans + u.p * fan%P * po(u.fa,P-2)%P)%P;
            continue;
           }
           for(int i = 0 ;i < t[u.r+1].size();i++)
           {
                int l1 = u.r+1;
                int r1 = t[l1][i];
                int pa = mp[{l1,t[l1][i]}] ;
                int pf = mp2[{l1,t[l1][i]}];
                 pa = pa*u.p%P;
                int fa = u.fa * pf %P;

                que.push({l1,r1,pa,fa});
            
           }
     }
}
void solve()
{
      
      cin>>m>>n;
      for(int i =1;i<=m;i++)
      {
        int l,r,q,p;
        cin>>l>>r>>p>>q;
        int pa =  p*po(q,P-2)%P;
        int pf = (1-pa+P)%P;
        if(!mp.count({l,r}))
        {
               mp[{l,r}]=pa;
               mp2[{l,r}]=pf ;
               t[l].push_back(r);

        }
        else 
        {    
             int pg = (mp[{l,r}] * pf %P + pa* mp2[{l,r}] % P)%P ;
             mp2[{l,r}]=mp2[{l,r}] * pf %P ;
             mp[{l,r}]=pg ;
        }

       

       
      }
      for(auto p : mp2)
      { // cout<<p.se<<'\n';
          fan = fan * p.se %P;
      }
      for(int i =0 ;i<t[1].size();i++)
      {
        bfs(1,t[1][i],mp[{1,t[1][i]}]);
      }
      cout<<ans<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}