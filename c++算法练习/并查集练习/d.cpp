#include<iostream>
#include<map>
#include<algorithm>
using namespace std ;
int find(int x ,map<int,int>&mp)
{
     if(mp[x]==x) return x;
     return mp[x] = find(mp[x],mp ) ;
}
void solve()
{
      while(1)
      {  int x ,y ;
      map<int ,int > mp ;
      int ji= 0 ;
      int mi =1e9+7 ;
      int ma = -1e9+7 ;
          while(scanf("%d %d",&x,&y) )
          {   
                   if(x==0&&y==0) break ;
                   if(x==-1&&y==-1)  return ;
                  ma = max(x,ma) ;
                  ma = max(y,ma) ;
                  mi = min(x,mi) ;
                  mi = min(y,mi) ;
                    if(!mp.count(x)) mp[x] = x ;
               if(!mp.count(y)) mp[y] = y ;
                 if(find(x,mp)!=find(y,mp) )  mp[find(x,mp)] = find(y,mp) ;
                 else 
                  {  ji = 1; 
                
                  }



          }
        int sum = 0 ;
        map<int,int> ans; 
       for(int i = mi ; i<=ma ;i++ )
       {
          if(!mp.count(i))continue ;

          if(ans.count(find(i,mp))) continue ;
          else 
            {ans[find(i,mp)] = 1 ;
              sum++ ;
            }
            if(sum>=2)
            {  ji = 1 ;
                 break ;
            }
       }


       if(ji) printf("No\n") ;
       else printf("Yes\n") ;

      }
}
   

int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}