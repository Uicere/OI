#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+8;
int cnt[N];
int a[N],b[N];
int n,m,h;
priority_queue<pair<int,int> > add,del;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > add2,del2;
bool vis[N];
int val[N];
signed main(){
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(vis[b[i]]){
			while(add2.size()&&del2.size()&&add2.top()==del2.top()){
				add2.pop();
				del2.pop();
			}
			cnt[b[i]]+=a[i];
			add2.push({cnt[b[i]],b[i]});
			if(cnt[b[i]]-a[i]>0)del2.push({cnt[b[i]]-a[i],b[i]});
//			cout<<add2.size();
			continue;
		}
		h-=a[i];
		cnt[b[i]]+=a[i];
		while(add.size()&&del.size()&&add.top()==del.top()){
			add.pop();
			del.pop();
		}
		add.push({cnt[b[i]],b[i]});
		if(cnt[b[i]]-a[i]>0)del.push({cnt[b[i]]-a[i],b[i]});
//		cout<<i<<" "<<h<<endl;
		pair<int,int> tmp=add.top();
		while(add.size()&&add2.size()&&add2.top().first<add.top().first){
			h-=add2.top().first;
			vis[add2.top().second]=0;
			add2.pop();
			pair<int,int> tmp=add.top();
			add.pop();
			h+=tmp.first;
			vis[tmp.second]=1;
//			cout<<add.size()<<"v";
		}
		if(h<=0){
			cout<<i-1<<" ";
			pair<int,int> tmp=add.top();
			add.pop();
			add2.push({tmp.first,tmp.second});	
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
