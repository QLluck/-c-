#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool cmp(string a,string b)
{   int i = 5;
    while(i<=a.size()-1)
    {
        if(a[i]==':'||a[i]=='-')
        {
            i++;
            continue;
        }
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return 0;
        i++;
    }
    return 0 ;
}
ll f(string a,string b)
{  
   ll day = 3600*24;
}
int main()
{ 
  vector<string>arr;
  // 请在此输入您的代码
  for(int i =1 ;i<=520 ; i++)
   {  string s1;
    cin>>s1;
    arr.push_back(s1);
   }
  sort(arr.begin(),arr.end(),cmp);
  cout<<"--------------"<<'\n';
  for(int i =0 ;i<=519 ;i++)
  {
      cout<<arr[i]<<'\n';
  }
  

  return 0;
}