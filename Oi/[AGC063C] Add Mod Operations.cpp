#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+9;
ll a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]==a[j]&&b[i]!=b[j]) cout<<"No", exit(0);
    const ll P=accumulate(a+1,a+1+n,0ll)+accumulate(b+1,b+1+n,0ll)+1;
    const int m=min_element(a+1,a+1+n)-a;
    cout<<"Yes"<<'\n'<<n<<'\n';
    for(int _=1;_<n;_++){
        const int p=max_element(a+1,a+1+n)-a;
        const ll d=((b[m]-b[p]-a[m])%P+P)%P;
        const ll mod=a[p]+d;
        if(mod==0){ cout<<0<<' '<<ll(1e18)<<'\n'; continue; }
        for(int i=1;i<=n;i++) (a[i]+=d)%=mod;
        cout<<d<<' '<<mod<<'\n';
    }
    cout<<((b[m]-a[m])%P+P)%P<<' '<<P<<'\n';
    return 0;
}
