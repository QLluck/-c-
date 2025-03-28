#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
using namespace std ;
const int N = 1e5+7 ;
struct node
{
     int x ,y,w;
    
}arr[N];
int me[107]={0},it;
int n;
int ans=  0;
map<pair<int ,int >,int > mp;
bool sort_f(node a,node b)
{
     return a.w<b.w;
}
int find(int x )
{
     if(me[x]==x)return x ;
     else return me[x]=find(me[x]);
}
void kruskal()

{
      for(int i= 1 ;i<=it ;i++)
     {
           if(find(arr[i].x)!=find(arr[i].y))
           {
              ans+=arr[i].w;
              me[find(arr[i].x)]=find(arr[i].y);
           }
     }
}
void solve()
{
     cin>>n;
     for(int i =1 ; i<=n ;i++)me[i]=i;
     for(int i =1 ;i<=n ;i++)
     {
           for(int j =1 ; j<=n ;j++)
           {  int w ;
              cin>>w;
              if(i>=j)continue ;
              mp[make_pair(i,j)]=++it; 
              arr[it].x= i ;
              arr[it].y=j ;
              arr[it].w=w ;



           }
     }
     int q; 
     cin>>q ;
     for(int i =1 ;i<=q ;i++)
     {   int x ,y;
          cin>>x>>y;
          //ans+=arr[ mp[ make_pair(x,y)]].w;
          me[find(x)]=find(y); 
     }
     sort (arr+1,arr+it+1,sort_f);
     kruskal();
     cout<<ans<<'\n';
}

int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}