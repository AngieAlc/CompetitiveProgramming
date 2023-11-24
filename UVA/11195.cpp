/*
    Idea: Try all posibilities :) 
*/
#include <bits/stdc++.h> 
using namespace std; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 20; 

int ans, n; 
char a[N][N]; 
bool col[N], resta[2*N], suma[2*N]; 

void go(int can){
    if(can == n){
        ans++;  
        return; 
    }
    f(i,1,n+1){
        int re = can + 1 - i + 15, su = can + 1 + i; 
        if(a[can+1][i] == '.' and !col[i] and !resta[re] and !suma[su]){
            col[i] = resta[re] = suma[su] = 1; 
            go(can+1); 
            col[i] = resta[re] = suma[su] = 0; 
        }
    }
}
void solve(int test){
    cout << "Case " << test << ": "; 
  
    f(i,1,n+1) f(j,1,n+1) cin >> a[i][j]; 

    ans = 0; 
    go(0); 
    cout << ans << "\n"; 

    // clear
    f(i,0,N) col[i] = 0; 
    f(i,0,2*N) resta[i] = suma[i] = 0; 
}
int main(){
    int t = 0; 
    while(cin >> n){
        t++; 
        if(n == 0) break; 
        solve(t); 
    }
    return 0; 
}
