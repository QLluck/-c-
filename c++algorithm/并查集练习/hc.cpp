#include<iostream>
#include<map>
#include<algorithm>
using namespace std ;
#define ll long long 
const int N =5e4 +7 ;
int n,q ;
int me[N]={0} ;
int bu[N]={0} ;
int bei[N]={0} ;

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
    for(int i = 1 ; i<= n ;i++) 
     { me[i] = i ;
        
     }

 
   
    int ans = 0 ;
map<int,int> mp ;
    while(q--)
    {
       int k,x,y ;
       cin>>k>>x>>y ;
    if(x>n||y>n) 
    {   ans++ ;
    // cout<<1<<endl ;
    // cout<<' '<<x<<' '<<y<<endl ;
             continue ;
    }
    if(k==2&&x==y)
    {
         ans++;
        //  cout<<2<<endl ;
        //  cout<<' '<<x<<' '<<y<<endl ;
         continue ;
    }
       switch(k)
       {
            case 1:
           
          if( find(bu[find(x)])==find(y)) 
           {  ans++ ;
        //    cout<<3<<endl ;
        //    cout<<' '<<x<<' '<<y<<endl ;
           }
          else if( find(bu[find(y)])==find(x)) 
              {  ans++ ;
        //       cout<<4<<endl ;
        //    cout<<' '<<x<<' '<<y<<endl ;
           }
        
          
          else 
          {  
              if(find(bu[find(x)])!=0 && find(bu[find(y)])!=0) me[find(bu[find(x)])] = find(bu[find(y)]) ;
              if(find(bei[find(x)])!=0 && find(bei[find(y)])!=0) me[find(bei[find(x)])] = find(bei[find(y)]) ;
              if(find(bu[find(x)])!=0 && find(bu[find(y)])==0) 
                 {   
                     bu[find(y)] = find(bu[find(x)]) ;

                 }
              if(find(bei[find(x)])!=0 && find(bei[find(y)])==0) 
              {
                bei[find(y)] =find(bei[find(x)]) ;
              }
              me[find(x)] =find(y) ;

        
                
          }
            break ;

               case 2 :
                  if( find(x)==find(y))
                      {  ans++ ;
        //               cout<<5<<endl ;
        //    cout<<' '<<x<<' '<<y<<endl ;
           }
               else if( find(bu[find(y)])==find(x) )
                   {  ans++ ;
        //            cout<<6<<endl ;
        //            cout<<' '<< find(bu[find(y)])<<' '<<find(x)<<endl ;
        //    cout<<' '<<x<<' '<<y<<endl ;
           }
              else 
              {  
                  if( find(bei[find(x)])!=0 && find(bu[find(y)])!=0 ) me[find(bei[find(x)])] = find(bu[find(y)]) ;
                  if(find(bei[find(x) ])!=0&&find(bu[find(y)])==0 )   
                   { bu[find(y)] = find(bei[find(x)]) ;
                       bei[find( bei[find(x)])] = find(y) ;
                   }
                
          
    
             if(find(bu[find(x)])==0)  bu[find(x)] = find(y) ;
              else if( find(bu[find(x)])!=0) me[find(bu[find(x)])] = find(y) ;
              
              
           if(find(bei[find(y)])!=0) me[find(x)] = find(bei[find(y)]) ;
              if(find(bei[find(y)])==0) 
              { bei[find(y)] = find(x) ;
                bu[find(bu[find(y)])] =find(x) ;
              }

            
              
        
                
             }

              
               break ;
               case 3 :
               cout<<find(x) <<endl ;
               cout<<bu[find(x)]<<endl ;
               cout<<bei[find(x)]<<endl ;
               break ;
       }
    }
    cout<<ans<<endl ;

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}