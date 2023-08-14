#include<iostream>
#include<queue>
using namespace std;
const int N=1008;
double p[N][N],f[N],g[N],h[N];
int n;
bool vis[N];
queue<int> q; 
void upd(){
	int u=q.front();
	q.pop();
	vis[u]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		g[i]+=f[u]*p[i][u]*h[i];
		h[i]*=(1-p[i][u]);
		f[i]=g[i]/(1-h[i]);
	}
}
void solve(){
	for(int i=1;i<n;i++){
		f[i]=g[i]=h[i]=1;
	}
	f[n]=0;
	h[n]=1;
	q.push(n);
	while(q.size()){
		upd();
		int u;
		double v=1e9;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&f[i]<v){
				v=f[i];
				u=i;
			}
		}
		q.push(u);
		upd();
	}
}
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&p[i][j]);
			p[i][j]/=100;
		}
	}
	solve();
	printf("%.8lf",f[1]);
	return 0;
}
