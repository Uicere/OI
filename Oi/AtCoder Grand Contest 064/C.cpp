#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void read(T& x){
		x=0; char c=gc();
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void write(T x,char c='\n'){
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::read;
using IO::write;
deque<int> q;
signed main(){
	int n;
	cin>>n;
//	if(n%2==0){
//		assert(n%2==1);
//	}
	if(n&1){
		for(int i=1;i<=n;i+=2) q.push_front(i);
		int c=!((n/2)&1);
		for(int i=2;i<=n;i+=2){
			c^=1;
			for(int j=1;j<=i;j++){
				if(c){
					q.push_back(i+1);
					q.push_back(i);
				}
				else{
					q.push_back(i);
					q.push_back(i+1);
				}
				
			}
		}
		for(auto i:q){
			cout<<i<<" ";
		}
	}
	else{
//		assert(n%2!=0);
		for(int i=2;i<=n;i+=2) q.push_front(i);
		int c=0;
		for(int i=1;i<=n;i+=2){
			for(int j=1;j<=i;j++){
				if(c){
					q.push_back(i+1);
					q.push_back(i);
				}
				else{
					q.push_back(i);
					q.push_back(i+1);
				}
			}
		}
		if(q.front()==q.back()){
			for(int j=1;j<=n-1;j++){
				q.pop_back();
				q.pop_back();
			}
			for(int j=1;j<=n-1;j++){
				q.push_back(q.front());
				q.push_back(q.front()-1);
			}
		}
		for(auto i:q){
			cout<<i<<" ";
		}
	}
	return 0;
}
