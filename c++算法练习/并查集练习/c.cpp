#include<iostream>
#include<map>
using namespace std ;
const int N = 1e2+7 ;
#define ll long long
int n,m ;
map<int ,int > mp ;
int find(int x)
{
     if(mp[x]==x) return x ;
     return mp[x] = find(mp[x]) ;
}
void solve()
{
     
      while(   scanf("%d",&n ) )
      {
           if(n==0) return ;

           scanf("%d",&m) ;

           for(int i = 1 ; i<=n;i++) mp[i] = i ;
   
           while(m--)
           {
              int x,y ;
              scanf("%d %d",&x,&y) ;
            

              if( find(x)==find(y)) continue ;
              mp[find(x)] = find(y) ;

           }

           int ans = 0;
         map<int ,int > num ;
           for(int i = 1 ; i<=n ;i++)
           {
                if(!num.count(find(i)))
                {
                    ans++ ;
                    num[find(i)] = 1 ;
                } 

           }

     printf("%d\n",ans-1) ;
 
      }

   
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}