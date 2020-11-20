/*
gcd¾í»ý (gcdconv) std
by sun123zxy 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;

ll Rd(){
	ll ans=0;bool fh=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') fh=1; c=getchar();}
	while(c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	if(fh) ans=-ans;
	return ans;
}

const ll MOD=998244353;
#define _ %MOD
ll PMod(ll x){
	if(x<0) return x+MOD;
	else if(x>=MOD) return x-MOD;
	else return x;
}

const ll MXN=5E5+5;
ll P[MXN],mu[MXN];ll pN;
bool notP[MXN];
void LinearSieve(ll n){
	notP[1]=1;for(ll i=2;i<=n;i++) notP[i]=0;
	P[1]=0;mu[1]=1;
	pN=0;
	for(ll i=2;i<=n;i++){
		if(!notP[i]){
			P[++pN]=i;
			mu[i]=-1;
		}
		for(ll j=1;i*P[j]<=n;j++){
			notP[i*P[j]]=1;
			if(i%P[j]==0){
				mu[i*P[j]]=0;
				break;
			}
			mu[i*P[j]]=mu[i]*mu[P[j]];
		}
	}
}

class Poly{public:
	ll& operator [] (ll idx){return cof[idx];}
	ll n;vector<ll> cof;
	Poly(){}
	Poly(ll n){Resize(n);}
	void Resize(ll n){
		this->n = n;
		cof.resize(n+1,0);
	}
};
namespace PC{//PolyCalc
	void FMT(Poly& A,ll typ){
		ll n=A.n;
		Poly B(n);
		for(ll i=1;i<=n;i++){
			for(ll j=1;i*j<=n;j++){
				ll t=A[i*j];if(typ==-1) t=t*mu[j]_;
				B[i]=PMod(B[i]+t);
			}
		}
		A=B;
	}
	Poly GcdConv(Poly A,Poly B){
		ll n=min(A.n,B.n); 
		Poly C(n);
		FMT(A,1);FMT(B,1);
		for(ll i=1;i<=n;i++) C[i]=A[i]*B[i]_;
		FMT(C,-1);
		return C;
	}
}

ll N;

int main(){
	freopen("gcdconv.in","r",stdin);
	freopen("gcdconv_std.out","w",stdout);
	N=Rd();
	LinearSieve(N);
	Poly A(N),B(N);
	for(ll i=1;i<=N;i++) A[i]=Rd();
	for(ll i=1;i<=N;i++) B[i]=Rd();
	Poly C=PC::GcdConv(A,B);
	ll ans=0;
	for(ll i=1;i<=N;i++) ans^=C[i];
	printf("%lld",ans);
	return 0;
}
