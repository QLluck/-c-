#include<bits/stdc++.h>
using namespace std ;
void solve()
{
    string s ;
    cin>>s;
    map<int,int> mp;
    for(int i =0;i<s.size();i++)
    {
        mp[s[i]-'0']++;

    }
    string ans ="";
    for(int i =9; i>=0 ; i--)
    {
       int it =i;
       while(!mp[it])it++;
       mp[it]--;
       ans=ans+char(it+'0');

    }
    cout<<ans<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}