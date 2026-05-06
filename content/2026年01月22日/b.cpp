#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
char t[100][100];
int a[100][100],ita;
int b[N],itb;
int ma =0 ;
// map<int,int>mp;


void solve()
{
  
  int n;
  
  
}
void init()
{
     for(int i=1;i<=ma;i++)
    {
        for(int j=1;j<=ma;j++)
        {
            if(a[i][j]==1)t[i][j]='*';
            else t[i][j]='.';
        }
        // cout<<endl;
    }
}
void print()
{
    for(int i=1;i<=ma;i++)
    {
        for(int j=1;j<=ma;j++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
    }
}
int f(int i,int j){ return (1<=i&&i<=ma)&&(1<=j&&j<=ma) ;}
int ji(int i,int j)
{
    int ans= 0 ;
    if(f(i-1,j)&&a[i-1][j])ans++;
    if(f(i+1,j)&&a[i+1][j])ans++;
    if(f(i,j-1)&&a[i][j-1])ans++;
    if(f(i,j+1)&&a[i][j+1])ans++;

    if(f(i-1,j-1)&&a[i-1][j-1])ans++;
    if(f(i+1,j+1)&&a[i+1][j+1])ans++;
    if(f(i+1,j-1)&&a[i+1][j-1])ans++;
    if(f(i-1,j+1)&&a[i-1][j+1])ans++;
    return ans;

}
void tui()
{
     for(int i=1;i<=ma;i++)
     {
        for(int j=1;j<=ma;j++)
        {
            if(t[i][j]=='.')
            {
                if(ji(i,j)==3)t[i][j]='*';
            }
            else 
            {
                if(ji(i,j)==3||ji(i,j)==2)continue;
                else t[i][j]='.';
            }
        }
     }
       for(int i=1;i<=ma;i++)
     {
        for(int j=1;j<=ma;j++)
        {
            if(t[i][j]=='.')
            {
                a[i][j]=0;
            }
            else 
            {
                a[i][j]=1;
            }
        }
     }
     
}
void te()
{
    int n;
    ma= 20;
    for(int i=1;i<=ma;i++)
    {
        for(int j=1;j<=ma;j++)a[i][j]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x+5][y+5]=1;
    }
    int o =0 ;
    init();
    int it= 0 ;
    while(1)
    {
        cin>>o;
        cout<<(++it)<<endl;
        if(o==1);
        else break;
        // init();
        print();
        tui();
    }
    
}
signed  main()
{
    // ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)
    te();
}
// 10
// 10 1
// 9 3
// 8 1
// 8 2
// 8 3
// 6 2
// 6 3
// 6 4
// 5 2
// 4 4

// 10
// 11 0
// 10 2
// 9 0
// 9 1
// 9 2
// 6 2
// 6 3
// 6 4
// 5 2
// 4 4
//6
// 10
// 12 -1
// 11 1
// 10 -1
// 10 0
// 10 1
// 6 2
// 6 3
// 6 4
// 5 2
// 4 4

//10
// 10
// 12 -1
// 11 1
// 10 -1
// 10 0
// 10 1
// 5 3
// 5 4
// 5 5
// 4 3
// 3 5








