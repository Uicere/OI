#include<iostream>
#include<queue>
#include<assert.h>
using namespace std;
const int N=3e6+8;
int n,k;
deque<int> mn,mx;
template<typename T>inline void read(T &x){
	x=0;T f=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>=48&&ch<=57){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
int a[N];
int main(){
//	freopen("pil10f.in","r",stdin);
	read(k),read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(mn.size()&&a[mn.back()]>a[i]) mn.pop_back();
		mn.push_back(i);
		while(mx.size()&&a[mx.back()]<a[i]) mx.pop_back();
		mx.push_back(i);
		while(a[mx.front()]-a[mn.front()]>k){
			if(mn.front()<mx.front()) j=mn.front()+1,mn.pop_front();
			else j=mx.front()+1,mx.pop_front();
		}
		ans=max(ans,i-j+1);
//		int last=mn.front();
//		for(auto it=mn.begin();it!=mn.end();++it){
////			assert(a[last]>=a[*it]);
//			last=*it;
//			cout<<a[*it]<<" ";
//		}
//		cout<<endl;
	}
	write(ans);
	return 0;
}
