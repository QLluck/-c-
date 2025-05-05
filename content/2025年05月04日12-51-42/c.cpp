#include<bits/stdc++.h>
using namespace std ;

int arr[10]={0};
stack<char> sta;
void solve()
{
   string s ;
   cin>>s;
   int sum =0 ; 
   int flag=1;
   for(int i =0;i<s.size();i++)
   {
     if(s.empty())sta.push(s[i]);
     else 
     {  
         sta.push(s[i]);
         flag=1;
         while(flag&&sta.size()>=3)
         {
             char c1= sta.top();
             sta.pop();
             char c2= sta.top();
             sta.pop();
             char c3= sta.top();
             sta.pop();

             if(c1==c2&&c1==c3&&c2==c3)
             {
                flag=1;
                continue;
             }
             else
             {  flag=0;
                sta.push(c3);
                sta.push(c2);
                sta.push(c1);
             }
         }
        
     }
   }
   if(sta.empty())
   {
     cout<<"NAN"<<'\n';
     return;
   }
   string ans="";
   while(!sta.empty())
   {
     ans+=sta.top();
     sta.pop();
   }
   reverse(ans.begin(),ans.end());
cout<<ans<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}