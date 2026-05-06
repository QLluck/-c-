#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define se second 
#define fi first 
#define PII pair<int,int>
const int N = 1e5+7;
const int mod = 128;
int ans[N];
string a[N];
int cnt=0;
unordered_map<string ,int >mp;
unordered_map<string,int>me;
// int shu =0 ;
int f2 = 0;
int f1=0;
int si(string &s)
{
    int sum=0;
    for(int i=1;i<=s.size()-1;i++)
    {    sum<<=1;
        if(s[i]=='1')sum++;
    }
    return sum;
}
int dfs(string &s,int u )
{
    int n= s.size()-1;
    // cout<<s.substr(u,n-u+1)<<'\n';
    if(mp[s.substr(u,n-u+1)])
    {  
        return mp[s.substr(u,n-u+1)];
    }
    // me[s.substr(u,n-u+1)]=1;
    // shu++;
    // int n = s.size();
    int res= 0;
    for(int i=1;i<=n-u+1 &&i<=5;i++)
    {
        // if(res==0)return 0;
        
        // int num2 = me[s.substr(u+i,n-u-i)];
        // cout<<num<<' '<<u<<' '<<i<<' '<<s.substr(u,i)<<'\n';
        int num = me[s.substr(u,i)];
        if(num)
        {
            // // flag=1;
            
            int sum =0 ;
             if(u+i-1<=n)
                sum=dfs( s,u+i);
            else sum=1;
                if(sum>=2)f2=1;
                if(sum>=1)f1=1;
                sum%=mod;
                //    cout<<s<<' '<<' '<<num<<' '<<sum<<'\n';
                if(sum*num>=2)f2=1;
                if(sum*num>=1)f1=1;
                res+=(sum*num)%mod;
                res%=mod;
        }
    }
    // if(flag)
    // cout<<u<<' '<<res<<'\n';
    mp[s.substr(u,n-u+1)]=res;
    return res;
    // else return 0;
}

bool f(string &a,string &b){return a.size()<b.size();}
void solve()
{
   
//    shu=0;
 
   int n,m;
   mp.clear();
   cin>>n>>m;
   me.clear();
   int it =0 ;
   for(int i=1;i<=m;i++)
   {
    char c;
    string s;
    cin>>c>>s;
    me[s]++;
    s=" "+s;
    if(mp[s.substr(1,s.size()-1)])mp[s.substr(1,s.size()-1)]++;
    else 
    {
     a[++it]=s;
     mp[s.substr(1,s.size()-1)]++;
    }
    // cout<<s<<'\n';
    
   }
   sort(a+1,a+it+1,f);
   for(int i=1;i<=it;i++)
   {
    int res =mp[a[i].substr(1,a[i].size()-1)];
    // cout<<res<<'\n';
    mp[a[i].substr(1,a[i].size()-1)]=0;

     res += dfs(a[i],1);
     res%=mod;
     mp[a[i].substr(1,a[i].size()-1)]=res;
    //  cout<<a[i]<<' '<<res<<'\n';      
   }
   string ss;
   cin>>ss;
   ss = " "+ss;
    f2=0,f1=0;
    mp[ss.substr(1,ss.size()-1)]=0;
   int ans =dfs(ss,1);
   int me2 = me[ss.substr(1,ss.size()-1)];
   ans+=me2;
   if(me2>=1)f1=1;
   if(me2>=2)f2=1;
//    ans+=me[ss.substr(1,ss.size()-1)];
//    cout<<ans<<'\n';
 if(f2==1)
 { 
    ans%=mod;
     cout<<"puppymousecat"<<' '<<ans<<'\n';
    // cout<<"happymorsecode"<<'\n';
 }
 else if(f1==1)
 {
    
   cout<<"happymorsecode"<<'\n';
 }
 else 
 {
cout<<"nonono"<<'\n';
 }
//  cout<<shu<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // init();
    cin>>t;
    while(t--)
    solve();
}