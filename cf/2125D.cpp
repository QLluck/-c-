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
struct node1
{
      int u,v,next;
};
int h[N]={0},it;
node1 g[4*N];
void insert(int u,int v)
{
      g[++it].u = u;
      g[it].v =v ;
      g[it].next = h[u];
      h[u]=it;
} 
// vector<int > t[N];
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
     que.push({l,r,p,mp2[{l,r}]});
     while(que.size())
     {
           node u = que.front();
           que.pop();
           if(u.r==n)
           {
            ans =( ans + u.p * fan%P * po(u.fa,P-2)%P)%P;
            continue;
           }
           for(int i = h[u.r+1] ;i !=0;i=g[i].next)
           {
                int l1 = u.r+1;
                int r1 = g[i].v;
                int pa = mp[{l1,r1}] ;
                int pf = mp2[{l1,r1}];
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
               insert(l,r);

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
      for(int i =h[1] ;i!=0;i=g[i].next)
      {
        bfs(1,g[i].v,mp[{1,g[i].v}]);
      }
      cout<<ans<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}