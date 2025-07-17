#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N =1e6+7;
int arr[N]={0};
int t[N]={0};
int b[N]={0};
int q[N][4]={0};
int u[N]={0},it;

int lowbit(int x){return x&-x;}

void add(int x,int k)
{
	while(x<N)
	{
		t[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x )
{
	 int res= 0;
	 while(x)
	 {
		 res+=t[x];
		 x-=lowbit(x);
	 }
	return res;
}
int check(int mid,int fen)
{
	return query(mid)<fen ;
}
void solve(){
	int n,m;
	cin>>n>>m;
	map<int,int>mp;
	int mi = 1e9+7;
	int ma= 0 ;
	for(int i =1;i <=n;i++)
	{ cin>>arr[i];
		
		
        if(!mp[arr[i]])
        {
             mp[arr[i]]=1;
             u[++it]=arr[i];
        }
		b[i]=arr[i];
	}
	
	for(int i =1;i<=m; i++)
	{
	int x ,d ;
		cin>>x>>d;
        
		 q[i][1]=b[x];
     b[x]+=d;
         q[i][2]=b[x];
        if(!mp[b[x]])
        {
             mp[b[x]]=1;
             u[++it]=b[x];
        }



	}

    sort(u+1,u+it+1);
    for(int i =1; i<=it ;i++)mp[u[i]]=i;
    for(int i =1; i<=n ;i++)arr[i]=mp[arr[i]];
    for(int i=1 ; i<=m;i++)
    {
         for(int j=1; j<=2 ;j++)q[i][j]=mp[q[i][j]];
    }
    for(int i =1;i <=n;i++)
    {
          add(arr[i],1);
          ma = max(arr[i],ma);
          mi = min(arr[i],mi);
    }
    int l =0 ;
    int sum =n ;
    int fen =n/2;
    int ln=0;
    int rn=0;
    while(n-query(l+1)>=fen)
    { 
         l++;
    }

    for(int i =1; i<=m;i++)
    {  //cout<<"--------"<<i<<'\n';
       int x = q[i][1];
       int y = q[i][2];
       //cout<<"YES1"<<'\n';
    		add(x,-1);
            //cout<<"YES2"<<'\n';
           // cout<<x<<' '<<y<<'\n';
		add(y,1);
  while(n-query(l+1)>=fen)
    { 
         l++;
    }
          // cout<<"YES3"<<'\n';
        
		// ma =max(x,ma);
		// mi = min(y,mi);
		
		// int l= mi -1; 
		// int r = ma +1;
		// int fen = n - n/2 ;
		// while(l+1<r)
		// {
		// 	int mid=(l+r)>>1;
        //    // cout<<mid<<' '<<l<<' '<<r<<'\n';
		// 	if(check(mid,fen)) l= mid;
		// 	else r =mid ;
            
		// }
//		for(int i =1; i<=ma ;i++)
//		{
//			 cout<<query(i)<<' ';
//			
//		}
//		cout<<'\n';
//cout<<r-1<<' '<<r<<'\n';

		// if(query(r)>fen)cout<<query(r-1)<<'\n';
		// else 
		// cout<<query(r)<<'\n';
     // cout<<"???"<<'\n';
     cout<<query(l)<<'\n';
    }

	for(int i=1; i<=n;i++)add(b[i],-1);



	
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
//	T=1;     
	while(T--){
		solve();
	}
}