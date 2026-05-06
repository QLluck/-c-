#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vowelConsonantScore(string s) {
        int v =0,c=0;
        for(auto i : s)
            {
                if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')v++;
                else if(i!=' '&& !('1'<=i&&i<='9'))c++;
            }
        int ans =0 ;
        if(c>0)ans=v/c;
        else ans=0;
        return ans;
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        #define se second 
        #define fi first 
        #define PII pair<int,int>
        int n = capacity.size();

        vector<pair<int,int> > a(n);
        vector<pair<int,int>> dp(budget+2);
      for(int i=0;i<n;i++)
      {
         a[i].se = costs[i];
         a[i].fi = capacity[i];
        //  cout<<a[i].fi<<' '<<a[i].se<<' '<<i<<'\n';
      }
      auto cmp = [](pair<int,int> &a, pair<int,int>&b)->bool{
        if(a.se==b.se)return a.fi<b.fi;
        else return a.se<b.se;
      };
      sort(a.begin(),a.end(),cmp);
    //   auto cmp = [](const pair<int,int>& a,int b)->bool{
    //     return a.fi <b;
    //   };
    // for(auto i :a )
    //  cout<<i.fi<<' ';
    // cout<<'\n';
    // for(auto i :a )cout<<i.se<<' ';
    // cout<<'\n';
    
      int it =0 ;
      for(int i=0 ;i<n;i++)
      {
            // auto ta = upper_bound(a.begin(),a.end(),i);
            // if(ta==a.begin())continue;
            // else ta--,dp[i].fi=ta-a.begin();
            while(it<a[i].se)
            {
                ++it;
                dp[it]=dp[it-1];
                // cout<<"????"<<dp[it].fi<<' '<<dp[it].se<<' '<<dp[it-1].fi<<' '<<dp[it-1].se<<' '<<it<<'\n';
            }
        if(i==0)dp[it].fi=0;
        else if(i==1)
        {
            dp[it].se=i;
            if(a[dp[it].fi].fi < a[i].fi) swap(dp[it].fi,dp[it].se);
        }
        else 
        {
        vector<PII> tmp(3) ;
        tmp[0]={a[dp[it].fi].fi,dp[it].fi};
        tmp[1]={a[dp[it].se].fi,dp[it].se };
        tmp[2]={a[i].fi,i};
        sort(tmp.begin(),tmp.end());
        // for(auto i : tmp)cout<<i.fi<<' '<<i.se<<'\n';
        dp[it].fi=tmp[2].se;
        dp[it].se=tmp[1].se;
     
        }
        //    cout<<dp[it].fi<<' '<<dp[it].se<<' '<<i<<'\n';
            
            
      }
      while(it<budget)++it,dp[it]=dp[it-1];
      for(auto i : dp)cout<<i.fi<<' ';
      cout<<'\n';
      for(auto i : dp)cout<<i.se<<' ';
      cout<<'\n';
    // for(int i=0;i<n;i++)
    // {

    // }
      int ans =0 ;
      budget--;
      for(int i=a[0].se;i<=budget-1;i++)
      {
          
           int it1=dp[i].fi,it2=dp[budget-i].fi;
           if(it1!=it2)ans=max(a[it1].se+a[it2].se,ans);
            it1=dp[i].se,it2=dp[budget-i].fi;
            if(it1!=it2)ans=max(a[it1].se+a[it2].se,ans);
            it1=dp[i].fi,it2=dp[budget-i].se;
        if(it1!=it2)ans=max(a[it1].se+a[it2].se,ans);
            it1=dp[i].se,it2=dp[budget-i].se;
        if(it1!=it2)ans=max(a[it1].se+a[it2].se,ans);
            // cout<<it1<<' '<<it2<<'\n';
      }
      return ans;
      
        
    }
};
int main()
{
    string s;
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for(auto &i : a)cin>>i;
    for(auto &i : b)cin>>i;
    // for(auto i : a)cout<<i<<' ';
    // cout<<'\n';
    // for(auto i : b)cout<<i<<' ';
    // cout<<'\n';
    // getline(cin,s);
    Solution solve ;
    cout<<solve.maxCapacity(a,b,m);
}