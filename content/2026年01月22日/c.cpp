#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
char t[100][100];
int a[100][100],ita;
PII a1[4][10];
PII a2[4][10];
int b[N],itb;
int ma =0 ;
// map<int,int>mp;

void init1()
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
 
    // cin>>n;
    // for(int i=1;i<=n;i++)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     a[x+5][y+5]=1;
    // }
    int o =0 ;
    init1();
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

void init()
{    
    int it =0 ;
     a1[0][++it]={1,1};
     a1[0][++it]={2,1};
     a1[0][++it]={3,1};
     a1[0][++it]={1,2};
     a1[0][++it]={3,3};
     it =0 ;
     a1[1][++it]={1,1};
     a1[1][++it]={1,2};
     a1[1][++it]={2,1};
     a1[1][++it]={2,0};
     a1[1][++it]={3,2};
     it =0 ;
     a1[2][++it]={1,1};
     a1[2][++it]={1,0};
     a1[2][++it]={1,-1};
     a1[2][++it]={2,-1};
     a1[2][++it]={3,0};
     it =0 ;
     a1[3][++it]={-1,0};
     a1[3][++it]={1,0};
     a1[3][++it]={1,-1};
     a1[3][++it]={2,1};
     a1[3][++it]={2,-1};


    it =0 ;
     a2[0][++it]={1,1};
     a2[0][++it]={1,3};
     a2[0][++it]={2,3};
     a2[0][++it]={3,2};
     a2[0][++it]={3,3};
     it =0 ;
     a2[1][++it]={1,2};
     a2[1][++it]={2,3};
     a2[1][++it]={2,4};
     a2[1][++it]={3,2};
     a2[1][++it]={3,3};

     it =0 ;
     a2[2][++it]={1,3};
     a2[2][++it]={2,4};
     a2[2][++it]={3,2};
     a2[2][++it]={3,3};
     a2[2][++it]={3,4};

    it =0 ;
     a2[3][++it]={2,1};
     a2[3][++it]={2,4};
     a2[3][++it]={3,3};
     a2[3][++it]={3,4};
     a2[3][++it]={3,3};



   
   

    
}
void solve()
{
    int n;
    cin>>n;
    
    
    
        // n-=6;

   
        cout<<2*n-1<<'\n';
        for(int i=1;i<=2*n-1;i++)
        {
          
            cout<<i<<' '<<i<<'\n';
        }

    
    //       ma= 30;
  
    // te();

}

  


signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
 
    t=1;
    // cin>>t;
    while(t--)
    solve();



}
