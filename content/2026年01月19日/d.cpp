#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+10;
int a[N];
int tree[N<<2];
int trji[N<<2];
int tag[N<<2];
int ji[N];
int ls(int p){return p<<1 ;}
int rs(int p){return p<<1|1 ;}
int lowbit(int x){return x&-x;}
int t[N];
int n;
void add(int x,int d)
{
    while(x<=n)
    {
        t[x]+=d;
        x+=lowbit(x);
    }
}
int queryt(int x)
{
    int res =0 ;
    while(x)
    {
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
int qji(int l,int r)
{
    return queryt(r)-queryt(l-1);
}
void push_up(int p)
{
    tree[p]=tree[ls(p)] + tree[rs(p)];
    // trji[p]=trji[ls(p)]+trji[rs(p)];
}
void build( int p,int pl,int pr)
{
    tag[p]=0;
    if(pl==pr){tree[p]=a[pl];return;}
    int mid =(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void addtag(int p,int pl,int pr,int d)
{
    tag[p]+=d;
    tree[p]+=d*(pr-pl+1 - qji(pl,pr));
}
void push_down(int p,int pl,int pr)
{
    if(tag[p])
    {
        int mid =(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(int l,int r,int p,int pl,int pr,int d)
{
    if(l<=pl&&pr<=r)
    {
        addtag(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid = (pl+pr)>>1;
    if(l<=mid )update(l,r,ls(p),pl,mid,d);
    if(r>mid) update(l,r,rs(p),mid+1,pr,d);
    push_up(p);
}
int query(int l,int r,int p,int pl,int pr)
{
    if(pl>=l&&r>=pr)return tree[p];
    push_down(p,pl,pr);
    int res =0 ;
    int mid = (pl+pr)>>1;
    if(l<=mid)res+=query(l,r,ls(p),pl,mid);
    if(r>mid)res+=query(l,r,rs(p),mid+1,pr);
    return res;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    { cin>>a[i];
        t[i]=0;
    }
    for(int i=1;i<=n;i++)
    { 
        cin>>ji[i];

    }
    build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            int y;
            cin>>y;
        }
        else if(o==2)
        { int y;
            cin>>y;
        }
        else if(o==3)
        {
            int l,r,y;
            cin>>l>>r>>y;
            update(l,r,1,1,n,y);
        }
        else if(o==4)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,1,1,n)<<'\n';
        }
        
    }

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // scanf("%lld",&t);
    // cin>>t;

    while(t--)
    solve();
}