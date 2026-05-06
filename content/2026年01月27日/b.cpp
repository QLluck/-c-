#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
int x,y;
const int N = 5e6+7;
// char a[N][N];
int nex[N];
string s[N];
int t[N][30];
map<int,int>num;
int n;
int cnt= 0;
void build(string &s)
{
    int it =0 ;
    for(int i=0 ;i<s.size();i++)
    {
        int id = s[i]-'a';
        if(t[it][id])it=t[it][id];
        else if(t[it][id]==0)
        {
            cnt++;
            t[it][id]=cnt;
            it=cnt;
            for(int i=0 ;i<=26;i++)t[cnt][i]=0;
        }
    }
    num[it]++;
}
bool f(string &a,string &b)
{
    return a.size()<b.size();
}
int query(string &s,int jie )
{
    int it =0 ;
    int res= 0 ;
    for(int i=0 ;i<s.size();i++)
    {
        int id = s[i]-'a';
        if(t[it][id])
        { it=t[it][id];
           if((i+1)%jie==0) res+=num[it];
            // cout<<num[it]<<'\n';
        }
    }
    // num[it]++;
    res--;
    return res;
}
void ne(string &s)
{
    int len =s.size();
    int j =0,k=-1;
    nex[0]=-1;
    while(j<len)
    {
        if(k==-1||s[j]==s[k])
        {
            nex[++j]=++k;
        }
        else k=nex[k];
    }
}
void solve()
{
    cnt=0;
    num.clear();
    for(int i=0;i<=26;i++)t[0][i]=0;

   for(int i=1;i<=n;i++)cin>>s[i],build(s[i]);
   int ans= 0;
   int ans2=0;
      sort(s+1,s+n+1,f);
   for(int i=1;i<=n;i++)
   {
       ne(s[i]);
    //    cout<<s[i]<<'\n';
       int jie =0 ;
       int j= s[i].size();
           int num = j-nex[j];
        //    if(s[i].size()==1)ans+=query(s[i],1);
         if(j%num==0 && (j/num) >1 )
        {
            // cout<<"jie "<<(j/num)<<'\n';
            int xun = j/num;
            int chan = s[i].size()/xun;
            // cout<<chan<<'\n';
            ans+=query(s[i],chan);
        }
        else ans2+=query(s[i],s[i].size());

   }
   ans+=ans2/2;
   cout<<ans<<'\n';

//    cout<<cnt<<'\n';
    // int ans= 0 ;
    // for(int i=1;i<=n;i++)
    // {
    //     ans+=query(s[i]);
    // }
    // cout<<ans<<'\n';
  
   
  

}
signed main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
     while(scanf("%lld",&n)!=EOF)
    {   
          solve();
    
    }
  
}