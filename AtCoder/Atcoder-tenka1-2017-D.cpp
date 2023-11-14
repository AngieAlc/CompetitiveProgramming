/*
    Idea: Cada numero A <= k se puede representar de la forma: 
    A = X....(ultimos r digitos no se sabe)
    PERO se sabe que el (r-1)-bit de A es 0, mientras que el de k es 1. 
    Entonces solo se prueban todas las posibilidades haciendo brute force. 
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 1e5 + 5; 

int n, k; 
int a[N], b[N];

bool is(int x, int y){ // es x included in y 
    return (x&y) == x; 
}
int main(){
    cin >> n >> k; 
    
    f(i,1,n+1) cin >> a[i] >> b[i]; 

    int left = 0; 
    ll ans = 0; 

    fa(i,29,-1){
        if(i != -1 and (k&(1<<i)) == 0) {
            left *= 2; 
            continue; 
        }

        ll curr = 0; 
        f(j,1,n+1){
            if(is((a[j]>>(i+1)), left) and (i == -1 or (a[j]&(1<<i)) == 0))
                curr += (ll) b[j]; 
        }
        ans = max(ans, curr);  
        left = 2*left + 1;  
    }

    cout << ans << "\n"; 

    return 0; 
}
