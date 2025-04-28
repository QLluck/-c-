#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7;
int arr[N]={0};
int qian[N]={0};
int hou[N]={0};

void solve()
{
     int n,k;
     cin>>n>>k;
    priority_queue<int> que1;
    priority_queue<int> que2; 
     for(int i =1; i<=n;i++)cin>>arr[i];
     for(int i =1; i<=n;i++)
     {
          if(que1.empty())
          {
             que1.push(-arr[i]);
          }
          else if(-que1.top() <= arr[i])
          {
              que1.push(-arr[i]);
          }
          else if(-que1.top()>arr[i])
          {
             que2.push(arr[i]);
          }
          if(que1.size()-que2.size()>2)
          {
             int temp = -que1.top();
             que1.pop();
             que2.push(temp);
          }
          else if(que1.size()-que2.size()<=0)
          {
             que1.push(-que2.top());
             que2.pop();
             
          }
          qian[i]=-que1.top();

     }
     while(!que1.empty())que1.pop();
     while(!que2.empty())que2.pop();
     for(int i =n; i>=1;i--)
     {
        if(que1.empty())
        {
           que1.push(-arr[i]);
        }
        else if(-que1.top() <= arr[i])
        {
            que1.push(-arr[i]);
        }
        else if(-que1.top()>arr[i])
        {
           que2.push(arr[i]);
        }
        if(que1.size()-que2.size()>2)
        {
           int temp = -que1.top();
           que1.pop();
           que2.push(temp);
        }
        else if(que1.size()-que2.size()<=0)
        {
           que1.push(-que2.top());
           que2.pop();
           
        }
       
          hou[i]=-que1.top();
        }
        // for(int i =1; i<=n;i++)
        // {
        //     cout<<qian[i]<<' ';

        // }
        // cout<<'\n';
        for(int i =1; i<=n-2;i++)
        {
            if(qian[i]<=k&&arr[i+1]<=k)
            {
                cout<<"YES"<<'\n';
                return;
            }
        }
        for(int i=n ;i >=3;i--)
        {
             if(hou[i]<=k&& arr[i-1]<=k)
             {
                cout<<"YES"<<'\n';
                return;
             }

            }
        int l =1 ;
              while(l<=n&&qian[l]>k )l++;
        int r =n; 
            while(r>=1&&hou[r]<k)r--;
            if(l+1>=r)
            {
                cout<<"NO"<<'\n';
                return;
            }
            else if(r==0||l==n+1)
            {
                cout<<"NO"<<'\n';
                return;
            }
            else if(l+1<r)
            {
                 cout<<"YES"<<'\n';
                 return;
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