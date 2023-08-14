#include<iostream>
#define int long long
using namespace std;
int n,P;
const int N=409;
int inv[N+4];
int fac[N+4];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%P;
	}
	inv[n]=qmi(fac[n],P-2);
	for(int i=n-1;i>=1;i--){
		inv[i]=1LL*inv[i+1]*(i+1)%P;
	}
}
int C(int n,int m){
	if(n<m) return 0;
	return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;
} 
int f[N][N];
signed main(){
	cin>>n>>P;
	init(n);
	for(int i=1;i<=n;i++){
		f[i][i]=qmi(2,i-1);
		for(int j=1;j<i;j++){ 
			for(int k=1;k<j;k++){
				f[i][j]=(f[i][j]+1ll*f[i-k-1][j-k]*qmi(2,k-1)%P*C(j,k)%P)%P;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+f[n][i])%P;
	} 
	cout<<ans;
	return 0;
}
