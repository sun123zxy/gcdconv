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

ll Random(){
	return 1LL*RAND_MAX*rand()+rand();
}
const ll MOD=998244353;
int main(){
	freopen("gcdconv.in","w",stdout);
	srand(time(NULL));
	//ll N=2E3;
	ll N=4E5;
	printf("%lld\n",N);
	for(ll i=1;i<=N;i++) printf("%lld ",Random()%MOD);
	printf("\n");
	for(ll i=1;i<=N;i++) printf("%lld ",Random()%MOD);
	return 0;
}
