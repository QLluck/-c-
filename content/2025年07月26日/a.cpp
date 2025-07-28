#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int N = 4e5+7;
int t1[N]={0};
int t2[N]={0};
int me[N]={0},it;
int l[N];
int r[N];
int n;
int prime[N],cnt ;
int pme[N];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void pri()
{
	for(int i=2; i<N;i++)
	{
		if(!pme[i])prime[cnt++]=i;
		for(int j =0 ; j<cnt ;j++)
		{
			if(i*prime[j]>=N)break;
			pme[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int b[N]={0};
int c[N]={0};
void solve(){
	
	int m;
	cin>>m;
	int ma= 0 ;
	it =0 ;
	int it1= 0 ;
	unordered_map<int,int>  mp1;
	unordered_map<int,int> mp ;
	map<pair<int,int> ,int > mp2 ;
	for(int i =1;i<=m;i++)
	{
		int l1,r1;
		cin>>l1>>r1;
		if(!mp2[{l1,r1}]) mp2[{l1,r1}]=1,l[++it1]=l1,r[it1]=r1;
		
		if(!mp1[l1])me[++it]=l1,mp1[l1]=1;
		if(!mp1[r1])me[++it]=r1,mp1[r1]=1;
		
	}
	sort(me+1,me+it+1);
	for(int i=1;i<=it;i++)
	{
		mp[me[i]]=i;
		//	cout<<mp[me[i]]<<' '<<me[i]<<'\n';
		ma =max(ma,i);
	}
	for(int i=1;i<=it1;i++)
	{
		l[i]=mp[l[i]];
		r[i]=mp[r[i]];
		//cout<<l[i]<<' '<<r[i]<<'\n';
	}
	n=ma;
	for(int i =1; i<=it ;i++)t1[i]=0,t2[i]=0;
	for(int i=1;i<=it1;i++)
	{
		int l1 = l[i];
		int r1 = r[i];
		
		//add(l1,1,t1);
        t1[l1]+=1;
        t1[r1+1]-=1;
		
		int x = rng();
        t2[l1]+=x;
        t2[r1+1]-=x;
		
	}
	map<pair<int,int>,int >ans;
	int num=0;
    for(int i=1;i<=n;i++)t1[i]=t1[i]+t1[i-1],t2[i]=t2[i]+t2[i-1];
	for(int i=1;i<=it ;i++)
	{
		pair<int,int> pa ;
		pa.first =t1[i];
		pa.second = t2[i];
		
		if(!ans[pa])num++,ans[pa]=1;
		
		//	cout<<pa.first<<' '<<pa.second<<'\n';
	}
	cout<<num+1<<'\n';

	
	
	
}
signed  main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pri();
	int T; 
	T=1;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}