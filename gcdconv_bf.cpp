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

ll Gcd(ll a,ll b){
	if(b==0) return a;
	return Gcd(b,a%b);
}

const ll MOD=998244353;
#define _ %MOD
ll& MD(ll& x){return x=(x _ + MOD)_;}

const ll MXN=2E3+5;
ll N;
ll A[MXN],B[MXN],C[MXN];

int main(){
	freopen("gcdconv.in","r",stdin);
	freopen("gcdconv_bf.out","w",stdout);
	N=Rd();
	for(ll i=1;i<=N;i++) A[i]=Rd();
	for(ll i=1;i<=N;i++) B[i]=Rd();
	for(ll i=1;i<=N;i++) C[i]=0;
	for(ll i=1;i<=N;i++){
		for(ll j=1;j<=N;j++){
			ll gcd=Gcd(i,j);
			C[gcd]=(C[gcd]+A[i]*B[j])_;
		}
	}
	ll ans=0;
	for(ll i=1;i<=N;i++) ans^=C[i];
	printf("%lld",ans);
	return 0;
}
