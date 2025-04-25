#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std ;
const int N = 1e5 + 7;
#define ll long long 
struct node
{
    ll l, r, sum, la;
} t[N * 4];
ll arr[N];
ll n;
void pushup(ll p )
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}
void build(ll p ,ll l,ll r)
{
    node temp ={l,r,arr[l],1};
    t[p] = temp;
    if(l==r)
        return;
    ll m = (l + r) >> 1;
    build(p << 1, l, m);
    build(p << 1|1, m+1, r);
    pushup(p);
}
void update(ll p ,ll l,ll r )
 {  if(l<=t[p].l&&t[p].r<=r)
     {
           if(t[p].sum==(t[p].r-t[p].l+1))
              return;
    }
      if(t[p].l==t[p].r)
     { t[p].sum = (ll)sqrt(t[p].sum);
         return;
     }
      ll m = (t[p].l + t[p].r) >> 1;
      if(l<=m)
          update(p << 1, l, r);
      if(m<r)
          update(p << 1|1, l, r);
      pushup(p);
}
ll query(ll p ,ll l,ll r)
{
    if (l <= t[p].l && t[p].r <= r)
        return t[p].sum;
    ll m = (t[p].l + t[p].r) >> 1;
    ll sum = 0;
    if (l <= m)
      sum+=  query(p << 1, l, r);
    if (m < r)
        sum+=query(p << 1 | 1, l, r);
    return sum;
}
void print()
{
    for (int i = 1; i <= n;i++)
        printf("%lld ", query(1, i, i));
    printf("\n");
     } 
void solve()
{
    
    ll it = 0; 
    while (scanf("%lld",&n)!=EOF)
    {
        it++;
        printf("Case #%lld:\n", it);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        //cout<<1<<'\n'
            build(1, 1, n);
        ll q;
        scanf("%lld",&q);
        for (int i = 1; i <= q;i++)
        {
            ll x,l,r;
            scanf("%lld %lld %ld", &x, &l, &r);
            if(l>r)
                swap(l, r);
            if(x==0)
                update(1, l, r);
            else
                printf("%lld\n", query(1, l, r));
        }
        printf("\n");
    }
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}