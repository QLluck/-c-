#include<bits/stdc++.h>
const int N =5e5+7;
using namespace std ;
#define ll long long 


void solve()
{

    string s ;
    cin>>s;
  
    int l =0;
    int r =1e3-2 ;
    while(r<=1e6-1)
    {
        int l1 =0 ;
        int r1 = r;
        int num= 0;
        while(s[l1]==s[r1])
        {
            num++;
            l1++;
            r1++;

        }
        if(num>=1e3)
        {
            cout<<"NO"<<'\n';
            return;
        }
        r++;


    }
    cout<<"YES"<<'\n';
    
     
    
   

}


int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

  solve();
}