#include<bits/stdc++.h>
using namespace std;
const int N=100;
pair<int,int> a[N][N];
int cnt[N];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y;
			cin>>y;
			a[y][++cnt[y]].first=x;
			a[y][cnt[y]].second=i;
		}
	}
	int x;
	cin>>x;
	sort(a[x]+1,a[x]+cnt[x]+1);
	if(cnt[x]==0){
		puts("0");
		return 0;
	}
	vector<int> ans;
	ans.push_back(a[x][1].second);
	int last=a[x][1].first;
	for(int i=2;i<=cnt[x];i++){
//		cout<<a[x][i].second<<" "; 
//		
		if(a[x][i].first!=last){
			break;
		}
		else{
			ans.push_back(a[x][i].second);
		}
	}
	cout<<ans.size()<<endl;
	for(int i:ans){
		cout<<i<<" ";
	}
	return 0;
}
