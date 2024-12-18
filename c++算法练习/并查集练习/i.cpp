#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
int n,m ;
const int N =1e3 +7 ;
int me[N]={0} ;
struct node 
{
    int x ;
    int y ;
    int t;
};
vector<node> arr ;
vector<int> ti ;
int check(int mid);
int judge();
int find(int x) ;
int judge()
{
     map<int,int> mp1 ;
     int ji = 0 ; 
     for(int i = 1 ; i<=n ;i++)
     {if(mp1.count(find(i))) continue ;
      mp1[find(i)] =1 ;
       ji++ ;
         
     }
     if(ji>1)
     {
          
          return 1 ;
     }
     else return 0 ;
}
int find(int x)
{
     if(me[x]==x) return x ;
     return me[x]=find(me[x]) ;
}
int check(int mid)
{
   for(int i = 1 ; i<=n ;i++) me[i] = i ;
   for(int i = 0 ; i<arr.size() ;i++)
   {
      if(ti[mid]<arr[i].t) continue ;
      if(find(arr[i].x)!=find(arr[i].y))  me[find(arr[i].x)] =find(arr[i].y) ;
   }
   if(judge()) return 1 ;
   else return 0 ;


 
}



void solve()
{
     cin>>n>>m ;
     
      for(int i = 1 ; i<=n ;i++) me[i] = i ;
     for(int i = 1 ; i<=m ;i++)
     {   int x,y,t ;
     cin>>x>>y>>t ;
          node temp ={x,y,t} ;
          arr.push_back(temp) ;
          ti.push_back(t) ;

          if(find(x)!=find(y))
          {
             me[find(x)] = find(y) ;
          }
        
     }
     if(judge())
     { 
          cout<<-1<<endl ;
          return ;
     }
    
     sort(ti.begin(),ti.end()) ;
     ti.erase( unique(ti.begin(),ti.end()) ,ti.end()) ;

     int l = -1 ;
     int r = ti.size() ;
     while(l+1!=r)
     {
         int mid = (l+r)/2 ;
         
         if(check(mid)) l =mid ;
         else r= mid ;
     }
     cout<<ti[r]<<endl ;

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}