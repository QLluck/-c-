#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 1000+7;
vector<int> a[N];
void bfs()
{
     queue<int> que;
     map<int,int>mp;
     que.push(1);
     mp[1]=1;
     while(que.size())
     {
         int u =que.front();
         que.pop();
         for(int i =0 ;i<a[u].size();i++)
         {
             int v = a[u][i];
             if(mp[v])continue;
             mp[v]=1;
             cout<<u<<' '<<v<<' ';
             
             que.push(v);

         }
     }
}
void solve()
{
   
int n;
cin>>n;
for(int i=1;i<=n;i++)a[i].clear();
for(int i=2;i<=n;i++)
{
     int x = 1;
     int s= 1 ;
     while(s!=i)
     {
        x=s;
        cout<<"? "<<i<<' '<<x<<endl;
        int tmp ;
        cin>>tmp;
        s=tmp;
     }
     a[i].push_back(x);
     a[x].push_back(i);
}
cout<<"! ";

bfs();
cout<<' '<<endl;
    


}

// gcd(a,b) * a1 + gcd(a,b)*b1 ;  (a1 + b1 )/gcd(a,b)*b1 ;  a1 / gcd(a,b)*b1   + b1/gcd(a,b);
//
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    // te();
}//! 1 2 1 3 3 4