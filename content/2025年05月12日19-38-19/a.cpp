#include<bits/stdc++.h>

using namespace std ;
void solve()
{
     string s; 
     cin>>s;
     map<char,int> mp1;
     int n = s.size();
     for(int i =0 ;i<n;i++)
     {
        mp1[s[i]]++;
        if(mp1[s[i]]>1)break;
        if(i==n-1)break;
        int l = i+1 ;
        int r = n-1 ;
        while(l<=r)
        {  
           if(s[l]!=s[r])break;
           l++;
           r--;
           if(l>=r)
           {
             cout<<"HE"<<'\n';
             return;
           }

        }
     }
     cout<<"NaN"<<'\n';
}

int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}