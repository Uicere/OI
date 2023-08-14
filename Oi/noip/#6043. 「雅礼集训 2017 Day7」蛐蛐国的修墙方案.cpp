#include<iostream>
#include<vector>
using namespace std;
const int N=108;
vector<int> cir[N/2];
int p[N];
bool vis[N];
int tot,n;
char a[N];
void check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='(') sum++;
		else sum--; 
		if(sum<0) return;
	}
	if(sum==0){
		cout<<(a+1);
		exit(0); 
	}
	return ;
}
void dfs(int pos){
	if(pos==tot+1){
		check();
		return ;
	}
	int sz=cir[pos].size();
	if(sz==2){a[cir[pos][0]]='(',a[cir[pos][1]]=')',dfs(pos+1);return ;}
	for(int i=0;i<sz;i++){
		if(i&1){
			a[cir[pos][i]]='(';
		}	
		else{
			a[cir[pos][i]]=')';
		}
	}
	dfs(pos+1);
	for(int i=0;i<sz;i++){
		if(i&1){
			a[cir[pos][i]]=')';
		}	
		else{
			a[cir[pos][i]]='(';
		}
	}
	dfs(pos+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			++tot;
			int x=i;
			while(!vis[x]){
				vis[x]=1;
				cir[tot].push_back(x),x=p[x];
			}
		}
	}
	dfs(1);
	return 0;
}
