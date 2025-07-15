#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =1e5+7;

int arr[N]={0};
void solve()
{
    

  int a,b,c,d;
  cin>>a>>b>>c>>d;
  string s; 
  cin>>s;
  int ab=0;
  int ba=0;
  int a1 =0 ;
  int b1= 0 ;
  for(int i =0 ; i<s.size() ; i++)
  {
     if(i+1<s.size() && s[i]=='A'&&s[i+1]=='B')
     { ab++;
        i++ ;
        continue;
     }
     else if(i+1<s.size() && s[i]=='B'&&s[i+1]=='A')
     { ba++;
        i++;
        continue;
     }
     else if(i+1<s.size() && s[i]=='B'&&s[i+1]=='B')b1++;
     else if(i+1<s.size() && s[i]=='B'&&s[i+1]=='B')a1++;
     else if(s[i]=='B')b1++;
     else if(s[i]=='A')a1++;
     
     

  }
  if(ab<c||ba<d)
  {
    cout<<"NO"<<'\n';
    return;
  }
  ab-=c ;
  a-=ab;
  b-=ab;
  ba-=d ;
  a-=ba;
  b-=ba;
  if(a==a1&&b==b1)
  {
    cout<<"YES"<<'\n';
    
  }
  else cout<<"NO"<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}