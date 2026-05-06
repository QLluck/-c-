#include<bits/stdc++.h>
using namespace std;
// #define int long long 
const int N = 1e6+7;
#define PII pair<int,int>
#define fi first 
#define se second 
int a[N];
// int me[N];
int me[N];

struct node
{
    int o,fi,se;

};
node b[N];
int li[N];

int ans[N];
int find(int x)
{
    // if(me[x]==0)me[x]=x;
    if(me[x]==x)return me[x];
    else return me[x]=find(me[x]);
}
void solve()
{
    
   int n,m;
   int liit=0;
//    cin>>n;
scanf("%d",&n);
   int bit= 0 ;
   int ma= 0 ;
   for(int i=1;i<=n;i++)
   {
    bit++;
    b[bit].o=2 ;
    // cin>>b[bit].fi;
    scanf("%d",&b[bit].fi);
    // ma = max(b[bit].fi,ma);
    li[liit++]=b[bit].fi;
   }
   scanf("%d",&m);
   for(int i=1;i<=m;i++)
   {
    bit++;
    //  cin>>b[bit].o;
    scanf("%d",&b[bit].o);

     if(b[bit].o==2||b[bit].o==3)
     { 
        // cin>>b[bit].fi;
        scanf("%d",&b[bit].fi);
li[liit++]=b[bit].fi;
        //  ma = max(b[bit].fi,ma);
     }
     else 
     { 
        // cin>>b[bit].fi>>b[bit].se;
        scanf("%d",&b[bit].fi);
        scanf("%d",&b[bit].se);
        li[liit++]=b[bit].fi;
        li[liit++]=b[bit].se;
        //  ma = max(b[bit].fi,ma);
        //  ma = max(b[bit].se,ma);
     }
   }
//    for(int i=1;i<=bit;i++)cout<<b[i].o<<' '<<b[i].fi<<' '<<b[i].se<<'\n'; 
int it =0 ;
// cout<<ma<<'\n';
sort(li+1,li+1+liit);
liit = unique(li+1,li+liit+1)-li -1;
// for(int i=1;i<=liit;i++)cout<<li[i]<<' ';
// cout<<'\n';
// cout<<liit<<'\n';

for(int i=1;i<=N;i++)me[i]=i;
map<int,int>mpc;
map<int,int>fan ;
for(int i=1;i<=liit;i++)fan[i]=li[i];
for(int i=bit;i>=1;i--)
{
    if(b[i].o==3)
    {    int x = lower_bound(li+1,li+liit+1,b[i].fi)-li;
        mpc[x]=1;
    }
    else if(b[i].o==2)
    {    int x = lower_bound(li+1,li+liit+1,b[i].fi)-li;
        // b[i].fi=b[i].fi;
        if(!mpc[find(x)])
        {
            it++;
            ans[it]=fan[find(x)];
        }
    }
    else if(b[i].o==1)
    {
        int x =lower_bound(li+1,li+liit+1,b[i].fi)-li , y =lower_bound(li+1,li+liit+1,b[i].se)-li;
        if (x==y)continue;
        else if(find(x)==y)continue;
        x=find(x),y=find(y);
         if(x!=y)
        { 
            me[x]=y;
            // find(x),find(y);
        }
        else 
        {
            // find(x),find(y);
            me[x]=y;
            me[y]=y;
        }
    }
}
for(int i=it;i>=1;i--)
{ 
    // cout<<ans[i]<<' ';
    printf("%d ",ans[i]);

}
printf("\n");
   
  

    



}

signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // pai();
    // cin>>t;
    scanf("%d",&t);
     while(t--)solve();
}