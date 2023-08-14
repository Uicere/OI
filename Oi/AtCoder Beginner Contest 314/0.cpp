#include <bits/stdc++.h>
#define lint long long
#define rint register int
using namespace std;
inline int read(){
	char c;int f=1,res=0;
	while(c=getchar(),!isdigit(c))if(c=='-')f*=-1;
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res*f;
}
const int N=1e3+5,inf=1e9;
double p[N][N],f[N],g[N],h[N];
//最后的f才是答案,其为g/(1-h) 
int q[N],tot,n;//q实质上是拓扑序排列
bool vis[N];//判断是否在队列里面 
inline void upd(){//用队头来更新 
	int j=q[tot];
	for(rint i=1;i<=n;++i){
		if(vis[i])continue;
		g[i]+=f[j]*p[i][j]*h[i];
		h[i]*=1-p[i][j];
		f[i]=g[i]/(1-h[i]);
	}
}
inline void solve(){
	for(rint i=1;i<n;++i)
		f[i]=g[i]=h[i]=1;
	f[n]=0;h[n]=1;
	//恰好都是1 
	vis[n]=true;
	q[++tot]=n;upd();
	while(tot<n){
		int id;double v=inf;
		for(rint i=1;i<=n;++i)
			if(!vis[i]&&f[i]<v)
				v=f[i],id=i;
		vis[id]=true;
		q[++tot]=id;upd();
	}
}
int main(){
	n=read();
	if(n==1){return puts("0"),0;}
	for(rint i=1;i<=n;++i)
		for(rint j=1;j<=n;++j)
			p[i][j]=read()/100.0;
	solve();
	printf("%.8lf",f[1]);
	return 0;
}


