#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+8;
int cnt[N];
int a[N],b[N];
int n,m,h;
priority_queue<pair<int,int> > add,del;
bool vis[N];
signed main(){
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(vis[b[i]]) continue;
		h-=a[i];
		cnt[b[i]]+=a[i];
		while(del.size()&&add.top()==del.top()){
			add.pop();
			del.pop();
		}
		add.push({cnt[b[i]],b[i]});
		if(cnt[b[i]]-a[i]>0)del.push({cnt[b[i]]-a[i],b[i]});
//		cout<<i<<" "<<h<<endl;
		if(h<=0){
			cout<<i-1<<" ";
			pair<int,int> tmp=add.top();
			add.pop();
			h+=tmp.first;
			vis[tmp.second]=1;
			s++;
			if(s>=m) break;
		}
	}
	for(int i=s;i<=m;i++){
		cout<<n<<" "; 
	}
	return 0;
}
