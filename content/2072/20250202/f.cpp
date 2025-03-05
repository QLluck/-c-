#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+7 ;
#define ll long long 
int nex[N]={0};
void pi(string s1,string s2)
{   
      for(int i =1,j=0 ; i<s2.size() ;i++)
      {  while(j!=0 &&s2[j]!=s2[i])
      {
          j =nex[j-1];
      }
          if(j==0||s2[i]==s2[j])
          {
              nex[i]=j+1 ;
          }
      }
}
void solve()
{

     string s1 ;
     string s2 ;
     cin>>s1>>s2 ;



}
int main()
{
      ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
      int t;
      cin>>t ;
      while(t--)
      solve();
}