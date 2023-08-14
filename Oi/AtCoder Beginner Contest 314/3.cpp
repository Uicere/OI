#include<bits/stdc++.h>
using namespace std;
const int N=3e5+8;
int n,m;
int nxt[N],pre[N];
int last[N];
int ss[N];
int a[N];
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	memset(last,-1,sizeof last);
	memset(pre,-1,sizeof pre);
	memset(ss,-1,sizeof ss);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
		if(last[x]==-1){
			last[x]=i;
		}
		else{
			pre[i]=last[x];
			last[x]=i;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(ss[a[i]]==-1){
			ss[a[i]]=i;
		}
	}
	for(int i=0;i<n;i++){
		if(pre[i]!=-1){
			cout<<s[pre[i]];
		}
		else{
			cout<<s[ss[a[i]]];
		}
	}
	return 0;
}
