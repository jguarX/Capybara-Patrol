#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;

int N;
const ll mod=998244353;
ll X[200100],Y[200100];
ll P,Q;
vector<ll> pdiv[200100];
map<ll,ll> pw[200100];

ll md_exp(ll x, ll m=mod-2, ll mod1=mod){
    ll n=1; x%=mod1;
    while(m){
        if(m&1){n*=x; n%=mod1; x=x*x%mod1; m>>=1;}
        else{x=x*x%mod1; m>>=1;}
    }
    return n;
}

void solve(){
    ll i,j,x,r;
    cin>>N;
    for(int i=0; i<N; i++){cin>>X[i]>>Y[i];}
    for(int i=0; i<N; i++){
        x=Y[i];
        for(j=2; j*j<=x; j++){
            if(x%j==0){
                pdiv[j].push_back(i); 
                while(x%j==0){
                    x/=j; pw[i][j]++;
                }               
            }
        }
        if(x>1){
            pdiv[x].push_back(i); 
            pw[i][x]++;
        }
    }
    ll C=1; Q=1;
    for(i=2; i<=200000; i++){
        if(pdiv[i].size()){
            ll mx_exp=0;
            for(auto& tmp:pdiv[i]){
                mx_exp=max(mx_exp,pw[tmp][i]);
            }
            Q=Q*md_exp(i,mx_exp)%mod;
            ll S=0;
            ll k=md_exp(i,mx_exp);
            ll phi=(i-1)*(k/i); //for calculating modular inverse using Euler's Totient Theorem
            for(auto& j:pdiv[i]){
                S+=(X[j]*md_exp(i,mx_exp-pw[j][i])%k)*(md_exp(Y[j]/md_exp(i,pw[j][i]),phi-1,k)%k)%k;
            }
            S%=k;
            if(S==0){
                C=C*(k%mod)%mod; C%mod;
            }
            else{
                while(S%i==0){
                    C=C*i%mod;
                    S/=i;
                }
            }

        }
    }
    for(int i=0; i<N; i++){
        P=(P+X[i]%mod*Q%mod*md_exp(Y[i])%mod)%mod;
    }
    cout<<(P%mod*md_exp(C))%mod<<'\n'<<(Q*md_exp(C))%mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    solve();
}