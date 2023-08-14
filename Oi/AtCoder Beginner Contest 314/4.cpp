#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int cnt[N];
int a[N],b[N];
char c[N];
bool vis[N];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	bool flag=0;
	vector<pair<int,char> >S;
	for(int i=m;i>=1;i--){
		int t=a[i];
		if((t==2||t==3)&&!flag){
			flag=1;
			if(t==2) transform(s.begin(),s.end(),s.begin(),::tolower);
			else transform(s.begin(),s.end(),s.begin(),::toupper);
		}
		if(t==1){
			if(!vis[b[i]]){
				vis[b[i]]=1;
				int x=b[i];
				char y=c[i];
				char sss=s[x-1];
				if(flag){
					if(sss>='A'&&sss<='Z'){
						
						if(y>='a'&&y<='z') y-=32;s[x-1]=y; 
//						transform(s.begin(),s.end(),s.begin(),::toupper);
					}
					else{
						
						if(y>='A'&&y<='Z') y+=32;
s[x-1]=y;
//						cout<<(char)sss;
//						transform(s.begin(),s.end(),s.begin(),::tolower);
					}
					
				}
				else{
					S.push_back({x-1,y});
				}
				
			}
		}
	}
	for(auto i:S){
		s[i.first]=i.second;
	}
	cout<<s<<endl;
	return 0;
}
