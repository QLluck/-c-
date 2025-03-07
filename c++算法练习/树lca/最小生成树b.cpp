#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
const int N =2e5+7 ;
struct node
{
     int x,y,w;
}arr[N];
int it ;
int me[N]={0};
bool sort_f(node a ,node b){return a.w<b.w;}
int find(int x )
{
     if(me[x]==x)return x ;
     else return me[x]=find(me[x]);
}
void add(int x ,int y,int w ,map<pair<int ,int > ,int > & mp )
{
      if(x>y)swap(x,y);
      if(mp.count(make_pair(x,y)) )
      {
         arr[   mp[make_pair(x,y)]   ].w = min(w,arr[mp[make_pair(x,y)]].w);
      }
      else 
      {
          mp[make_pair(x,y)]=++it;
          arr[it].x=x;
          arr[it].y=y;
          arr[it].w=w;
      }
      
}
int ans = 0 ; 
void kruskal()
{
      for(int i =1; i<=it ;i++)
      {
          if(find(arr[i].x)!=find(arr[i].y))
          {
              me[find(arr[i].x)]=me[arr[i].y];
              ans+=arr[i].w;
             // cout<<arr[i].x<<' '<<arr[i].y<<' '<<arr[i].w<<'\n';
          }
      }
}
void solve()
{
     int num,n;
     while(cin>>num)
     {     if(num==0)return ;
        ans= 0  ;
        it =  0 ;
        map<pair<int ,int > ,int >  mp ;
        cin>>n;
          for(int i =1 ;i<=num ;i++) me[i]=i ;
          for(int i =1 ;i<=n ;i++)
          {
                 int x,y,w;
                 cin>>x>>y>>w;
                 add(x,y,w,mp);
          }
          sort (arr+1,arr+1+it,sort_f);
          kruskal();
          cout<<ans<<'\n';

          
     }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}

