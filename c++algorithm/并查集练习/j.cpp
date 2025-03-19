#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
int n,m ;
const int N =1e3 +7 ;
map<string,string> mp ;
string find(string s)
{
     if(mp[s]==s) return s;
     return  mp[s]=  find(mp[s]) ;
}

void solve()
{  
    string s1 ;
    string s2 ;

    while(cin>>s2)
    {   if(!mp.count(s2.substr(1,s2.size()-1))) mp[s2.substr(1,s2.size()-1)] = s2.substr(1,s2.size()-1) ;
          if(s2[0]=='$')return ;
          if(s2[0]=='#')
          { 
            
           
             s1=s2 ;
            continue ;
          }
          if(s2[0]=='+')
          {
              mp[s2.substr(1,s2.size()-1 )] =  find(s1.substr(1,s1.size()-1) ) ;
              continue ;
          }
          if(s2[0]=='?')
          {
            cout<<s2.substr(1,s2.size()-1)<<' '<<find(s2.substr(1,s2.size()-1))<<endl  ;
          }
          

    }
}



int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  
     solve() ;
}