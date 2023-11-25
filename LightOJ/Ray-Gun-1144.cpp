/*
    Idea: 
    The problem is the same as finding E = sum_i(1..m) [gcd(i, n) == 1]
    Mobius inversion:
    E = sum_i(1..m) sum_d (1..n) [d/gcd(i, n)] u(d)
    E = sum_i(1..m) sum_d (1..n)[d/i] [d/n] u(d)
    E = sum_d (1..n) (m/d) (n/d) u(d) --> We do this with a for loop over the minimum between m and n. 
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 1e6 + 5, inf = 2e9;  
 
int mobius[N]; 
bool prime[N]; 

void precalc(){
    f(i,1,N) mobius[i] = 1, prime[i] = true; 
    f(i,2,N){
        if(!prime[i]) continue; 
        for(int j = i; j < N; j += i){
            prime[j] = false; 
            if(j % (i * i) == 0) mobius[j] = 0;  
            else mobius[j] *= -1; 
        }
    } 
}

int main(){
    precalc(); 

    int t; cin >> t; 
    f(i,1,t+1){
        ll m, n;  
        cin >> m >> n; 

        ll ans = 0; 
        f(i,1,min(n,m)+1){
            ans += (ll) mobius[i] * (m / i) * (n / i); 
        }
        if(n > 0) ans++; 
        if(m > 0) ans++; 

        cout << "Case " << i << ": " << ans << "\n"; 
    }
    return 0; 
}
