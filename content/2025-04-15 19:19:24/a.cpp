#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+7 ;
#define ll long long 
int me[N]={0};



void solve()
{
    int q ;
    cin>>q;
    deque<ll> que ;
    int flag =1 ;
    ll sum1=0 ;
    ll sum0 = 0 ;
    ll pix0=0;
    ll pix1=0 ;
    while(q--)
    {
        int x ;
        cin>>x;
       
        if(x==3)
        {
            ll k ;
            cin>>k ;
            if(flag==1)
              { que.push_back(k);
               //cout<<sum1<<'\n';
                sum1+= k*que.size();
               // cout<<sum1<<' '<<k*que.size()<<'\n';
                sum0+=pix0;
                sum0+=k ;

                pix0+=k ;
                pix1+=k;

              }
              else if(flag==0)
              {
                que.push_front(k);
                sum0+= k*que.size();
                sum1+=pix1;
                sum1+=k ;
                pix1+=k ;
                pix0+=k;


              }
        }
        else if(x==2)
        {
             flag= !flag;
        }
        else if(x==1)
        {
            if(flag==1)
            {
                ll k = que.back();
                que.pop_back();
                que.push_front(k);

                sum1+=pix1;
               // cout<<pix1<<' '<<k*que.size()<<'\n';
                sum1-=que.size()*k;

                sum0-=pix0;
                sum0+=que.size()*k;
                

            }
            else if(flag==0)
            {
                ll k = que.front();
                que.pop_front();
                que.push_back(k);

                sum0+=pix0;
                sum0-=que.size()*k;

                sum1-=pix1;
                sum1+=que.size()*k;
            }
        }


  
      if(flag)cout<<sum1<<'\n';
      else cout<<sum0<<'\n';
  
    }

}
 





int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}