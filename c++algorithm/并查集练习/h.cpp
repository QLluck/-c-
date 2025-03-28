#include<iostream>
#include<map>
#include<algorithm>
using namespace std ;
#define ll long long 
const int N =5e4 +7 ;
int n,q ;
int me[N]={0} ;
int bu[N]={0} ;
//居然没思路 这是 并查集吗
//写废了
int find(int x)
{
      if(me[x]==x) return x ;
      return me[x] = find(me[x]) ;
}
void solve()
{
    cin>>n>>q ;
    for(int i = 1 ; i<= n ;i++) me[i] = i ;
    map<int,int> mp1 ;
    map<int,int> mp2 ;
    int ans = 0 ;
    while(q--)
    {
       int k,x,y ;
       cin>>k>>x>>y ;
    if(x>n||y>n) 
    {   ans++ ;
         continue ;
    }
    if(k==2&&x==y)
    {
         ans++;
         continue ;
    }
       switch(k)
       {
            case 1:
             if( !mp1.count(find(x))&&!mp2.count(find(x))&&!mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                  me[find(x)] = find(y) ;
                  mp1[find(x)] = 1 ;
                  mp1[find(y)] = 1 ; 
             }
             else if( !mp1.count(find(x))&&!mp2.count(find(x))&&!mp1.count(find(y))&&mp2.count(find(y)) )
             {
                    me[find(x)] = find(y) ;
                  mp1[find(x)] = 1 ;
                  mp1[find(y)] = 1 ; 
             }
             else if( !mp1.count(find(x))&&mp2.count(find(x))&&!mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                    me[find(y)] = find(x) ;
                  mp1[find(x)] = 1 ;
                  mp1[find(y)] = 1 ; 
             }
             else if( mp1.count(find(x))&&!mp2.count(find(x))&&!mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                    me[find(y)] = find(x) ;
                 
                  mp1[find(y)] = 1 ; 
             }
             else if( !mp1.count(find(x))&&!mp2.count(find(x))&&mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                    me[find(x)] = find(y) ;
                 
                  mp1[find(x)] = 1 ; 
             }
             else if( mp1.count(find(x))&&mp2.count(find(x))&&!mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                    me[find(y)] = find(x) ;
                 
                  mp1[find(y)] = 1 ; 
             }
             else if( !mp1.count(find(x))&&!mp2.count(find(x))&&mp1.count(find(y))&&mp2.count(find(y)) )
             {
                    me[find(x)] = find(y) ;
                 
                  mp1[find(x)] = 1 ; 
             }
             else if( mp1.count(find(x))&&!mp2.count(find(x))&&mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                    me[find(x)] = find(y) ;
                 
             }
             else if( !mp1.count(find(x))&&mp2.count(find(x))&&!mp1.count(find(y))&&mp2.count(find(y)) )
             {

              me[find(bu[find(x)] ) ] = find(bu[find(y)]) ;

                    me[find(x)] = find(y) ;



                    mp1[find(x)] = 1 ;
                  mp1[find(y)] = 1 ; 
                 
             }

              else if( mp1.count(find(x))&&!mp2.count(find(x))&&!mp1.count(find(y))&&mp2.count(find(y)) )
             {
                  me[find(x)] = find(y) ;
                 
                  mp1[find(y)] = 1 ; 
             }
              else if( !mp1.count(find(x))&&mp2.count(find(x))&&mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                  me[find(y)] = find(x) ;
                 
                  mp1[find(x)] = 1 ; 
             }
             else if(mp1.count(find(x))&&!mp2.count(find(x))&&mp1.count(find(y))&&mp2.count(find(y)) )
             {
                  me[find(x)] = find(y) ;
             }
             else if(mp1.count(find(x))&&mp2.count(find(x))&&mp1.count(find(y))&&!mp2.count(find(y)) )
             {
                  me[find(y)] = find(x) ;
             }
             else if(!mp1.count(find(x))&&mp2.count(find(x))&&mp1.count(find(y))&&mp2.count(find(y)) )
             {
                   if( find(bu[find(x)]) == find(y)) ans++ ;
                   else if( find(bu[find(y)]) ==find(x)) ans++ ;
                   else if( find(bu[find(x)]) ==find(bu[find(x)]) ) 
                   {
                      me[find(x)] = find(y);

                   }
                     else if( find(bu[find(x)]) !=find(bu[find(x)]) ) 
                   {
                      me[find(x)] = find(y);
                      
                   }
             }






         



            break ;

               case 2 :
                
                 
               break ;
       }
    }

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}