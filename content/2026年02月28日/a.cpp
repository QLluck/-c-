#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define se second 
#define fi first 
//PGB
//
//123
const int N = 1e6+7;

struct node 
{
    int p,g,b;
};
node a[300];
node b[300];
int mp[100];
int mp2[100];
int ans[N],it;
int po(int a,int b)
{
    int res =1;
    while(b)
    {
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    string s ="0";
    s+=s2[0];
    s+=s2[1];
    s+=s2[3];
    s+=s2[4];
    s+=s2[6];
    s+=s2[7];

    // cout<<s<<'\n';
    for(int i=0 ;i<=9;i++)
    {
        a[i].p=0;
        a[i].g=0;
        a[i].b=0;
        b[i].p=0;
        b[i].g=0;
        b[i].b=0;
        mp[i]=0;
        mp2[i]=0;
    }
    int n =  (s1[0]-'0')*100000 + (s1[1]-'0')*10000+(s1[3]-'0')*1000+(s1[4]-'0')*100+(s1[6]-'0')*10 +(s1[7]-'0');
    // cout<<n<<'\n';
    // cout<<1<<'\n';
    for(int i=0 ;i<s2.size();i++)
    {   
        int c = s1[i]-'0';
        if(c<0)c+=100;
        // cout<<' '<<s1[i]<<' '<<c<<'\n';
        if(s2[i]=='P')b[c].p++;
        if(s2[i]=='B')b[c].b++;
        if(s2[i]=='G')b[c].g++;
    }
   
    int it=0;
  for(int i=1;i<=999999;i++)
  {    
    int nn1 = (i/100000 %10) *10 + i/10000 %10;
    int nn2 = (i/1000 %10)*10 +i/100 %10 ;
    int nn3 = (i/10 %10)*10 +i%10;
    
    if(nn1+nn2!=nn3)continue;
    // cout<<nn1<<nn2<<nn3<<'\n';
    
    for(int j=0 ;j<=9;j++)
    {
        a[j].p=0;
        a[j].g=0;
        a[j].b=0;
        mp[j]=0;
        mp2[j]=0;
    }
    int num = i;
      for(int j=1;j<=6;j++)
    {
       int n1=num%10;
       num/=10;
       mp[n1]++;

    }
    num=i;
    int num2=n;
     int f= 1;
    for(int j=6;j>=1;j--)
    {
        
       
        int n2 = num2%10;
        int n1 = num%10;
        num2/=10;
        num/=10;
       
        if(s[j]=='G'&&n1!=n2)f=0;
        else if(s[j]=='G'&&n1==n2)a[n2].g++, mp[n2]--;
        else if(s[j]=='P'&&n1==n2)f=0;
        else if(s[j]=='B'&&n1==n2)f=0;
      
    }
    if(f==0)continue;

   num2=n;
   num=i;
      for(int j=6;j>=1;j--)
    {
          int n2 = num2%10;
        int n1 = num%10;
        num2/=10;
        num/=10;
       
        if(s[j]=='G')continue;

         mp2[n2]++;
         if(mp2[n2]<=mp[n2])a[n2].p++;
        else a[n2].b++;
    }
//    if(i==221335)
//    {
//       for(int j =0 ;j<=9;j++)
//       {
//         cout<<j<<'\n';
//         cout<<a[j].b<<' '<<b[j].b<<'\n';
//         cout<<a[j].p<<' '<<b[j].p<<'\n';
//       }
//    }
    for(int j =0 ;j<=9;j++)
    {
       if(b[j].b)
       {
          if(a[j].b==b[j].b&&a[j].p==a[j].p)continue;
          else f=0;
       }
       else
       {
         if(a[j].p>=b[j].p)continue;
         else f=0;
       }
        
    }
    if(f)ans[++it]=i;
  }


  cout<<it<<'\n';
  for(int i=1;i<=it;i++)
  {
    // cout<<ans[i]<<'\n';
    for(int j=6;j>=1;j--)
    {
        if(j==4)cout<<'+';
        if(j==2)cout<<'=';
      if(j>1 )cout<<(ans[i]/ po(10,j-1)  %10)   ;
      else cout<<ans[i]%10;
    }
    cout<<'\n';
  }

    


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)solve();
}