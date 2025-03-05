// 顺序表
#include <bits/stdc++.h>
using namespace std; 
const int N = 2e5+7  ;
#define ll long long 
int arr[N]={0};
void solve()
{
    ll n,x,k;
    cin>>n >>x>>k;
    string s ;
    cin>>s ;

    int  flag = 0  ; 
     arr[0]= x ;
     ll it1 = -1 ;
     ll it2 = -1 ;
       for(int i =0 ; i<s.size() ; i++)
       {
           if(s[i]=='L')arr[i+1]=arr[i]-1 ;
           else arr[i+1]=arr[i]+1 ;
           if(arr[i+1]==0&&flag==0)
           {
              flag =1 ;
              it1 = i ;
              arr[i+1] = -x ;
           }
           if(arr[i+1]==0&&flag ==1)
           {
              flag =2; 
              it2 = i ;
              break ;
           }
       }

        if(flag==0)
        {
               cout<<0<<'\n';
        }
        else if(flag==1)
        {
              if(k>=it1+1)cout<<1<<'\n';
              else cout<<0<<'\n';
        }
else 
        {   
             if(k<it1 +1 )
             {
                 cout<<0<<'\n';
             }
             else if(k<= 2*(it1+1 ) + (it2 - it1 -1 ))cout<<1<<'\n';
             

        }

    return ;


    


    
   
       
   
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}