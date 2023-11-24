/*
    Idea: the new elements should only be one of the given n elements in the sequence. 
    dp[i][j] = minimum #operations such that the last element of the range [1..i] is 
    exactly the j-th element when sorting the n numbers.  

    mini[i][j] : more efficient way to record the previous dp state
    mini[i][1] : minimum #op when the last element is included in the prefix [1..i] (of the ordered array)
*/
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 5005;
const ll inf = 1e18; 

int n;  
ll a[N], b[N], mini[N][2]; 

int main(){
    cin >> n; 

    f(i,1,n+1) {
        cin >> a[i]; 
        b[i] = a[i];
    }

    sort(b+1, b+n+1); 
    
    mini[0][0] = mini[0][1] = inf; 

    f(i,1,n+1){
        f(j,1,n+1){ // [1..i] acaba en este b[j]
            ll val = abs(a[i] - b[j]) + mini[j][0]; 
            mini[j][1] = min(mini[j-1][1], val); 
        }
        f(j,1,n+1){
            mini[j][0] = mini[j][1]; 
        }
    }

    cout << mini[n][0] << "\n"; 

    return 0; 
}
