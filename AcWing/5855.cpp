#include<bits/stdc++.h>
using namespace std;
void solve()
{
     int n,m;
     cin>>n>>m;
     map<string ,string > mp;
     for(int i  =1; i<=n;i++)
     {
         string s;
         string ji;
         cin>>s>>ji;
         mp[s]=ji;
         
     }
     for(int i =1; i<=m;i++)
     {
         string s="";
         string s1;
         cin>>s1;
         int it=0 ,len =1;
         while(it<s1.size())
         {
            while((len<=s1.size()-it) && mp.count(s1.substr(it,len))==0 ) len++;
            if(len>s1.size()-it)break;
            s+=mp[s1.substr(it,len)];
            cout<<s1.substr(it,len)<<'\n';
            it = it+len;

            
         }
         cout<<s<<'\n';
     }
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}