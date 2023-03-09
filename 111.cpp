//#include<bits/stdc++.h>
#include<iostream>
#define debug puts("here")
#define mem(a,i) memset(a,i,sizeof a)
#define mp(a,b) make_pair(a,b)
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
inline int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }
inline int lcm(int a,int b){return a/gcd(a,b)*b;}
int const maxn = 100+5,mod=998244353,INF=0x3f3f3f3f;
bool vis[maxn];
int g[maxn][maxn],dis[maxn],n;

int prim(int now)
{
	int ans=0;
	vis[now]=true;
	for(int i=1;i<=n;++i) dis[i]=min(dis[i],g[now][i]);
	for(int i=2;i<=n;++i)
	{
		int ind=-1,minn=INF;
		for(int j=1;j<=n;++j)
		{
			if(dis[j]<minn&&!vis[j])
			{
				ind=j,minn=dis[j];
			}
		}
		if(ind==-1) return -1;
		vis[ind]=true;
		ans+=dis[ind];
		for(int j=1;j<=n;++j) dis[j]=min(dis[j],g[ind][j]);
	}
	return ans;
}

int main()
{
	IO;
	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cin>>g[i][j];
			}
			dis[i]=INF;
			vis[i]=false;
		}
		int ans=prim(1);
		cout<<ans<<endl;
	}
	//ver1.1
}