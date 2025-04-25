#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7 ;
#define ll long long 
ll n,q,P;
struct node
{
    ll l,r ,sum,la,lax ;

}t[N*4];
ll arr[N]={0};
void pushup(ll p)
{
      t[p].sum =( t[p<<1].sum +t[p<<1|1].sum ) %P;
}

void pushdown(ll p)
{
  
      
          t[p<<1].sum = ((t[p<<1].sum*t[p].lax)+ (t[p].la *(t[p<<1].r -t[p<<1].l+1)) )%P;
          t[p<<1|1].sum = ((t[p<<1|1].sum*t[p].lax) +(t[p].la *(t[p<<1|1].r -t[p<<1|1].l+1)) )%P ;
          t[p << 1].lax = (t[p << 1].lax * t[p].lax) % P;
          t[p << 1 | 1].lax = (t[p << 1 | 1].lax * t[p].lax)  % P;
          t[p<<1].la = (t[p<<1].la*t[p].lax+t[p].la )  %P ;
          t[p<<1|1].la = (t[p<<1|1].la* t[p].lax + t[p].la)  %P ;
          t[p].lax = 1;
          t[p].la = 0 ;
          
      
}

void build(ll p,ll l,ll r )
{
     node temp = {l,r,arr[l]%P,0,1 };
     t[p]=temp ;
    // cout<<l<<' '<<r<<' '<<arr[l]<<' '<<t[p].sum<<'\n';
     if(l==r)return ;
     ll m = (l+r)>>1;
     build(p<<1,l,m);
     build(p<<1|1,m+1,r);
     pushup(p);

}
void update(ll p,ll l,ll r,ll w)
{
   
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].sum=(t[p].sum+w*(t[p].r-t[p].l+1))%P ;
        t[p].la =(t[p].la+w)%P ;
        return ;
    }
    pushdown(p);
    ll m =(t[p].r+t[p].l)>>1;
    if(l<=m) update(p<<1,l,r,w);
    if(m<r) update(p<<1|1,l,r,w);
    pushup(p);

}
void updatex(ll p,ll l,ll r ,ll w)
{
  

    if(l<=t[p].l &&t[p].r<=r)
    {
        t[p].sum =t[p].sum* w % P;
        t[p].lax =t[p].lax *w % P;
        t[p].la = t[p].la * w % P;

        return;
    }
    pushdown(p);
    ll m = (t[p].r + t[p].l) >> 1;
    if(l<=m) updatex(p<<1,l,r,w);
    if(m<r) updatex(p<<1|1,l,r,w);
    pushup(p);
}   
ll query(ll p,ll l,ll r)
{   // cout<<t[p].sum<<' '<<p<<'\n';
    if(l<=t[p].l&&t[p].r<=r)
    {
        return t[p].sum ;
    }
    
    pushdown(p);
    ll m =(t[p].r+t[p].l)>>1;
    ll sum = 0 ;
    if(l<=m) sum= (sum+query(p<<1,l,r))%P ;
    if(m<r) sum=(sum+query(p<<1|1,l,r))%P ;
    
    return sum ;
}
void print()
    {
        for(int i=1 ; i<=n ;i++)cout<<query(1,i,i)<<' ';
        cout<<'\n';
    }

void solve()
{
    cin>>n>>q>>P;
    for(int i=1 ;i<=n; i++)cin>>arr[i];
    // for(int i =1; i<=n ;i++)cout<<arr[i]<<' ';
    // cout<<'\n';
    build(1,1,n);
    // print();

    //print();
    for(int i =1 ;i<=q ; i++)
    {
         ll  x,l,r,k;
         cin>>x;
         if(x==1)
         {  cin>>l>>r>>k;
            updatex(1,l,r,k);
         }
         else if(x==2)
         {
             cin>>l>>r>>k;
             update(1,l,r,k);

            
         }
         else if(x==3)
         {
             cin>>l>>r;
             cout<<query(1,l,r)%P<<'\n';
         }
         
        //  cout << query(1, 1, 4) << '\n' ;
        //  cout << query(1, 1, 2) << '\n';
        //  cout << query(1, 3, 4) << '\n';
    }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}

    