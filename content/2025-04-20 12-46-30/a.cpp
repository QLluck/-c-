#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7 ;
struct node
{
     int l,r ;
     int num ;
};
int n;
node arr[N]={0};
int it;
int t[N]={0};
int lowbit(int x ){return x&-x;}
void add(int x,int k)
{
     
    while(x<=n)
    {
         t[x]+=k;
         x+=lowbit(x);
    }
}

int query(int x)
{
     int res= 0 ;
     while(x)
     {
         res+=t[x];
         x-=lowbit(x);
     }
     return res;
}
bool cmp(node a,node b)
{
     return a.num<b.num;
}
void solve()
{

    int m ;
    cin>>n>>m;
    it=0;
    
    map<pair<int,int> ,int >mp;
    for(int i=1 ;i<=n;i++)t[i]=0;
    for(int i=1; i<=m;i++)
    {
         int l,r ;
        cin>>l>>r;
        int num = r-l+1;
        if(mp.count(make_pair(l,r)))continue;
        mp[make_pair(l,r)]=1;
        arr[++it].l=l;
        arr[it].r=r;
       
            arr[it].num=num/2+1;
       
        
  
        
    }
    
    sort(arr+1,arr+it+1,cmp);
    int q; 
    cin>>q;
    int flag=0;
    if(q<arr[1].num)
    {
       flag=1;
    }
    int flag2=0;
    int ans =0;
    for(int i=1; i<=q; i++)
    {
          int a ;
          cin>>a ;
          add(a,1);
          int j =1;
          if(flag)continue;
          if(flag2)continue;
          while(i>=arr[j].num&&j<=it)
          {
               if(query(arr[j].r)-query(arr[j].l-1) >=arr[j].num)
               {
                
                flag2=1;
                ans=i;
            
               }
               j++;
              
          }



    }
    if(flag2)cout<<ans<<'\n';
    else 
    cout<<-1<<'\n';

 
     
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    
    int t; 
   // cout<<"YES"<<'\n';
    cin>>t;
    while(t--)
    solve();
}