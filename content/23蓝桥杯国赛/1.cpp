#include<bits/stdc++.h>
using namespace std ;
#define ll long long
string tostring(ll a)
{
	string s ="";
	while(a)
	{
		 s+= char(a%10 +'0');
	     a/=10;
	}
//	s.reserve(); 
    reverse(s.begin(),s.end());
   // cout<<s<<'\n';
	return s; 
}
 void solve()
{   
   
	ll n = 2023;
  for(ll i =1; i<= 1e14 ; i++)
  {   
     string s = tostring(i*n);
     int num = s.size();
     int flag= 1;
     //cout<<s<<'\n';
     for(int j =0 ; j<num ;j++)
     {
     	if(s[j]=='2'||s[j]=='3')continue;
     	else flag=0;
	 }
	 if(flag)cout<<s<<'\n';
  }
}
int main()
{
	// ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	 solve();
}
