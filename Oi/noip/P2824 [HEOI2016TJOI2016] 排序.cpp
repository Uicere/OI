#include<iostream>
#include<assert.h>
using namespace std;
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
const int N=1e5+8;
int a[N];
int n,k,q;
int mid;
int l[N],r[N],op[N];
struct tree{
	int l,r;
	int cnt1,tag;
}tr[N<<2];
void pushup(int u){
	tr[u].cnt1=tr[u<<1].cnt1+tr[u<<1|1].cnt1; 
}
void pushdown(int u){
	if(tr[u].tag==1){
		tr[u<<1].cnt1=tr[u<<1].r-tr[u<<1].l+1;
		tr[u<<1|1].cnt1=tr[u<<1|1].r-tr[u<<1|1].l+1;
		tr[u].tag=-1;
		tr[u<<1].tag=tr[u<<1|1].tag=1;
	}
	else if(tr[u].tag==0){
		tr[u<<1].cnt1=0;
		tr[u<<1|1].cnt1=0;
		tr[u].tag=-1;
		tr[u<<1].tag=tr[u<<1|1].tag=0;
	}
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r,tr[u].cnt1=0,tr[u].tag=-1;
	if(l==r){
		tr[u].cnt1=(a[l]>=mid);
		return ;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void update(int u,int l,int r,int val){
	if(l>r) return ;
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].cnt1=val*(tr[u].r-tr[u].l+1);
		tr[u].tag=val;
		return ;
	}	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid) update(u<<1,l,r,val);
	if(r>mid) update(u<<1|1,l,r,val);
	pushup(u); 
}
int query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r){
		return tr[u].cnt1;
	}
	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	int res=0;
	if(l<=mid) res=query(u<<1,l,r);
	if(r>mid) res+=query(u<<1|1,l,r);
	return res;
}
int check(int mid){
	build(1,1,n);
	for(int i=1;i<=k;i++){
		int op=::op[i],l=::l[i],r=::r[i];
		int cnt=query(1,l,r); 
		if(op==0){
			//Éı
			update(1,r-cnt+1,r,1);
			update(1,l,r-cnt,0);
		}
		else{
			//½µ
			update(1,l,l+cnt-1,1);
			update(1,l+cnt,r,0); 
		}
	}
	return query(1,q,q);
}
int main(){
	read(n),read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=k;i++){
		read(op[i]),read(l[i]),read(r[i]);
	}
	read(q);
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	write(ans);
	return 0;
}
