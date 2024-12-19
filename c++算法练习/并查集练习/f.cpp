#include<iostream>
#include<map>
#include<algorithm>
using namespace std ;
#define ll long long 
const int N =5e4 +7 ;
int n,q ;
int me[N]={0} ;
int pu[N]={0} ;
//居然没思路 这是 并查集吗
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

       switch(k)
       {
            case 1:
            if(!mp2.count(find(x))&&!mp2.count(find(y)))
            {
                  me[find(x)] = find(y) ;
                 
            }
            else if(!mp2.count(find(x))&&mp2.count(find(y)) )
            {
                    me[find(x)] = find(y) ;
            }
            else if(mp2.count(find(x))&&!mp2.count(find(y)) )
            {
                    me[find(y)] = find(x) ;
            }
            else if(mp2.count(find(x))&&mp2.count(find(y)) )
            {
                    
            }



            break ;


       }
    }

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}