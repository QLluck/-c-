#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e3+7;
// string a[N];
string a[N];
string biao[N];
void solve()
{
    // int a,b;
    map<string,int>mp;
    string h = "<censored>";
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>biao[i];
    }
//    int k;
   cin>>k;

    int it=0;
    //  s;
    int num=0;
   string s;
   it=1;
    while(cin>>s)
    {
        string sd;
        for(int g =1 ; g<=n;g++)
        {
            for(int i=0;i<s.size();i++)
         {
            int f =0 ;
            for(int j = 1; j<=s.size()-i;j++)
            {
                if(s.substr(i,j)==biao[g])
                {
                    s.erase(i,j);
                    num++;
                    sd = sd+h;
                    f=1;
                    i=i+j-1;
                   break;
                }
            }
            if(f==0)sd=sd+s[i],s.erase(i,1);
            }
        }
        a[it]=sd;
        it++;
        
    }
    if(num<k)
    {
    for(int i=1;i<=it;i++)
    { if(i!=it)cout<<a[i]<<' ';
        else cout<<a[i];
    }
    cout<<'\n';
    }
    else 
    {
        cout<<num<<'\n';
        cout<<"He Xie Ni Quan Jia!\n";
    }



    // cout<<b-a<<'\n';
    

}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}