#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =1e5+7 ;
struct node
{
     ll l,r,sum,lazzy ;
}t[4*N];
ll arr[N]={0};

void build(ll p , ll l ,ll r)
{
      node temp = {l,r,arr[l],0};
      t[p] = temp ;
      if(l==r)return ;
      ll m= (l+r)>>1;
      build(p<<1,l,m);
      build(p<<1|1,m+1,r);
   t[p].sum = t[p<<1].sum + t[p<<1|1].sum ;

}
void pushdown(ll p)
{
     if(t[p].lazzy)
     {
        t[p<<1].sum += t[p].lazzy*(t[p<<1].r - t[p<<1].l +1);
        t[p<<1|1].sum += t[p].lazzy*(t[p<<1|1].r - t[p<<1|1].l +1);
        t[p<<1].lazzy += t[p].lazzy;
        t[p<<1|1].lazzy += t[p].lazzy;
        t[p].lazzy =0 ;
     }
}
void update(ll p ,ll l,ll r,ll w)
{
    if(l<=t[p].l&&t[p].r<=r)
    {
          t[p].sum += w*(t[p].r - t[p].l +1);
          t[p].lazzy+=w;
          return ;
    }
    ll m = (t[p].l+t[p].r)>>1;
    pushdown(p);
    if(l<=m) update(p<<1,l,r,w);
    if(m<r) update(p<<1|1,l,r,w);
    t[p].sum = t[p<<1].sum +t[p<<1|1].sum ;
}

ll query(ll p ,ll l, ll r)
{
    if(l<=t[p].l&&t[p].r<=r)
    {
         return t[p].sum ;
    }
    ll m = (t[p].l+t[p].r)>>1;
    pushdown(p);
    ll sum = 0 ;
    if(l<=m)sum+= query(p<<1,l,r);
    if(m<r) sum+=query(p<<1|1,l,r);
    return sum ;
    
}

void solve()
{
   int n,m;
   cin>>n>>m;
   for(int i =1; i<=n ;i++)
   {
     cin>>arr[i];
   }
   build(1,1,n);
   for(int i =1; i<=m ;i++)
   { ll x ,l,r,k;
      cin>>x;
    switch(x)
    {   


        case 1 :
        cin>>l>>r>>k;
        update(1,l,r,k);
        break;
        case 2:

          cin>>l>>r;
        
         
          cout<<query(1,l,r)<<'\n';
          break;
        
          

            
    }
    
   }
   
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}