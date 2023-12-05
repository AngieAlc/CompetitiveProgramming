/*
    Idea: binary search in the answer 
    ordenar los 'm' posibles scores, se cumple que: 
    1st day: a1 < a2 < a3 < ... < am
    2nd day: b1 > b2 > b3 > ... > bm
    (se prueba porque en caso contrario siempre se puede hallar algo mejor)
    -> ademas a1..am & bm..b1 son numeros consecutivos desde el 1 (a excepcion de que ai != a & bi != b, para todo i)
    luego solo spdg a > b
    y casitos:
        - m >= a > b
        - a > m >= b
        - a > b > m
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 1e6 + 5; 
const ll inf = 1e18 + 5; 

ll a, b, score; 

ll get(ll sum, ll x){
    double xi = x, yi = sum-x, infi = inf; 
    if(yi >= infi/xi) return inf; 
    return x * (sum - x);
}
ll Maxi(ll l, ll r, ll sum){
    ll val = (sum+1)/2; 
    if(l <= val and val <= r) return get(sum, val); 
    if(val < l) return get(sum, l); 
    return get(sum, r); 
}
bool check(ll r){
    if(r < a){
        if(r < b) return get(r+1, (r+1)/2) < score; 
        return max(Maxi(1, r - b + 1, r+2), Maxi(1, b-1, r+1)) < score; 
    }
    if(a+1 <= r-b+2) return max(Maxi(1, a-1, r+2), Maxi(a+1, r-b+2, r+3)) < score; 
    return max(Maxi(1, r+1-b, r+2), Maxi(r+2-b, a-1, r+1)) < score; 
}
void solve(){
    cin >> a >> b;  
    if(a < b) swap(a, b); 

    score = a * b; 

    ll l = 0, r = inf; 
    while(l < r){
        ll m = (l+r+1)>>1; 
        if(check(m)) l = m; 
        else r = m - 1; 
    }
    cout << l << "\n"; 
}
int main(){
    int t; cin >> t; 
    while(t--) solve(); 
    return 0; 
}
