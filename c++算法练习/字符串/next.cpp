#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 ;
int nex[N]={0} ;
void getnext(string s)
{
        int i = 1; 
        int j = 0 ;
        nex[1] = 0 ;
        while(i<=s.size())
        {
             if(j==0||s[i]==s[j]) nex[++i] =++j ;
             else j = nex[j] ; 
        }
}

void solve()
{
     string s1 ;
     string s2 ;
     cin>>s1>>s2 ;
     getnext(s2 ) ;
     int n = 0 ;
     
   int i = 0;
   int j = 0 ;
         while(i<s1.size())
         { 
             if(j==0||s1[i]==s2[j])
             {
                    if(j==s2.size()-1)
               {
               cout<<i-j+1<<'\n' ;
               j=0 ;
               continue ;

               }

                   j++;
                   i++ ;
             } 
             else 
             {
                   j=nex[j] ;
             } 

           
         }
           for(int i = 0 ; i<s2.size() ; i++) cout<<nex[i]<<' ' ;
           cout<<'\n' ;
         
     

    

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
     solve() ;
}